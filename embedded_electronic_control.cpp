/*******************Implemented in: Visual Studio C++, Boost C++ ; Microcontroller Target: PIC (also ported for ARM microprocessor) **************************/
/* Author: Jubayer Ahmed
Email: cajubuvic@gmail.com
Phone: 7783175067
***********************************************************************************************************************************/


#include <system.h>

#pragma CLOCK_FREQ 19660800

#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)

class category
{
	private:
		unsigned char lowval, highval, midval;

	public:
		category() {};
		void setval(unsigned char&, unsigned char&, unsigned char&);
		unsigned char getlowval();
		unsigned char getmidval();
		unsigned char gethighval();

		unsigned char getshare(const unsigned char&);

      ~category() {};
};

category * ptrOutHeatKnob[5]; //create category object for Output HeatKnob
unsigned char KnobRanges[5][2]={{0,2}, {1,4}, {3,7}, {6,8}, {7,10}};
unsigned char knobMembership[5] = {0, 0, 0, 0, 0};
unsigned char l, m, h, pointCounter;

int defuzzXpoints[30] = {0};
int defuzzYpoints[30] = {0};

void category::setval(unsigned char &h, unsigned char &m, unsigned char &l)
{
	highval = h;
	midval = m;
    lowval = l;
}

unsigned char category::getlowval()
{
	return lowval;
}

unsigned char category::getmidval()
{
	return midval;
}

unsigned char category::gethighval()
{
	return highval;
}

unsigned char category::getshare(const unsigned char & input)
{
	//this member function returns the relative membership
	//of an input in a category, with a maximum of 1.0
	unsigned char output;
	unsigned char midlow, highmid;

	unsigned char lowvalget = getlowval();
	unsigned char midvalget = getmidval();
	unsigned char highvalget = gethighval();

	midlow = midvalget - lowvalget;
	highmid = highvalget - midvalget;

	//if outside the range, then output=0
	if((input <= lowvalget) || (input >= highvalget))
		output=0;
	else {
		if(input > midvalget)
			output = 100*(highvalget-input)/highmid;
		else
			if(input == midvalget)
				output = 100*1;
			else
           	output = 100*(input-lowvalget)/midlow;
	}
        return output;
}

void setRule(unsigned char loc, unsigned char val1, unsigned char val2)
{
	knobMembership[loc] = MIN(val1, val2);	//SET Y VALUE
	ptrOutHeatKnob[loc] = new category;            	
	//ptrOutHeatKnob[2]->setname(heatknobCatName[2]); //SET NAME
	l = KnobRanges[loc][0]; //SET X VALUES
	h = KnobRanges[loc][1];
	m = (h+l)/2;
	ptrOutHeatKnob[loc]->setval(h, m, l);
	
	defuzzXpoints[pointCounter] = l; defuzzYpoints[pointCounter++] = knobMembership[loc];
	defuzzXpoints[pointCounter] = m; defuzzYpoints[pointCounter++] = knobMembership[loc];
	defuzzXpoints[pointCounter] = h; defuzzYpoints[pointCounter++] = knobMembership[loc];
}

void swap(int *x, int *y)
{
	int c = *x;
	*x = *y;
	*y = c;
}

void insertion_sort(int s[], unsigned char n)
{
	unsigned char i, j;
	for(i=1;i<n;i++) {
		j=i;
		while((j>0) && (s[j]<s[j-1])) {
			swap(&s[j], &s[j-1]);
			j = j-1;
		}
	}
}


//Variables for storing Analogue Input Port A 0 and 1 ADC values
short FCV_IN1;
short FCV_IN2;

void FCD_ADC0_SampleADC()
{
	
	/*******Supported Devices****16F88********************/

		#define MX_ADC_CHANNEL		0
		#define MX_ADC_SAMP_TIME 	40
		#define MX_ADC_CONV_SP		3
		#define MX_ADC_VREF_OPT		0

		//set up ADC conversion
		unsigned char old_tris, cnt;
		adcon1 = 0x00;

		//assign VREF functionality
		#if (MX_ADC_VREF_OPT == 1)
			set_bit(adcon1, VCFG1);
		#endif

		//find appropriate bit
		#if (MX_ADC_CHANNEL == 0)
			#define MX_ADC_TRIS_REG  trisa
			#define MX_ADC_TRIS_MSK  0x01
			ansel = 0x01;
		#endif
		#if (MX_ADC_CHANNEL == 1)
			#define MX_ADC_TRIS_REG  trisa
			#define MX_ADC_TRIS_MSK  0x02
			ansel = 0x02;
		#endif		
		
		//sanity check
		#ifndef MX_ADC_TRIS_REG
		  	#pragma error "ADC Type 2 conversion code error - please contact technical support"
		#endif

		//store old tris value, and set the i/o pin as an input
		old_tris = MX_ADC_TRIS_REG;
		MX_ADC_TRIS_REG = MX_ADC_TRIS_REG | MX_ADC_TRIS_MSK;

		//assign conversion speed
		#if (MX_ADC_CONV_SP > 3)
			set_bit(adcon1, ADCS2);
		#endif

		//turn ADC on
		adcon0 = (0x01 | (MX_ADC_CONV_SP << 6)) | (MX_ADC_CHANNEL << 3);

		//wait the acquisition time
		cnt = 0;
		while (cnt < MX_ADC_SAMP_TIME) cnt++;

		//begin conversion and wait until it has finished
		adcon0 = adcon0 | 0x04;
		while (adcon0 & 0x04);

		//restore old tris value, and reset adc registers
		MX_ADC_TRIS_REG = old_tris;
		ansel = 0x00;
		adcon0 = 0x00;

		#undef MX_ADC_TRIS_REG
		#undef MX_ADC_TRIS_MSK
		#undef MX_ADC_SAMP_TIME
		#undef MX_ADC_CONV_SP
		#undef MX_ADC_VREF_OPT
		#undef MX_ADC_CHANNEL

}

short FCD_ADC0_ReadAsInt()
{
	
		short iRetVal;

		FCD_ADC0_SampleADC();

		iRetVal = (adresh << 2);
		iRetVal = iRetVal | (adresl >> 6);

		return (iRetVal);

}

//ADC1: //Macro implementations
void FCD_ADC1_SampleADC()
{
	
	/*******Supported Devices*******16F88******************/

		#define MX_ADC_CHANNEL		1
		#define MX_ADC_SAMP_TIME 	40
		#define MX_ADC_CONV_SP		3
		#define MX_ADC_VREF_OPT		0

		//set up ADC conversion
		unsigned char old_tris, cnt;
		adcon1 = 0x00;

		//assign VREF functionality
		#if (MX_ADC_VREF_OPT == 1)
			set_bit(adcon1, VCFG1);
		#endif

		//find appropriate bit
		#if (MX_ADC_CHANNEL == 0)
			#define MX_ADC_TRIS_REG  trisa
			#define MX_ADC_TRIS_MSK  0x01
			ansel = 0x01;
		#endif
		#if (MX_ADC_CHANNEL == 1)
			#define MX_ADC_TRIS_REG  trisa
			#define MX_ADC_TRIS_MSK  0x02
			ansel = 0x02;
		#endif		
		
		//sanity check
		#ifndef MX_ADC_TRIS_REG
		  	#pragma error "ADC Type 2 conversion code error - please contact technical support"
		#endif

		//store old tris value, and set the i/o pin as an input
		old_tris = MX_ADC_TRIS_REG;
		MX_ADC_TRIS_REG = MX_ADC_TRIS_REG | MX_ADC_TRIS_MSK;

		//assign conversion speed
		#if (MX_ADC_CONV_SP > 3)
			set_bit(adcon1, ADCS2);
		#endif

		//turn ADC on
		adcon0 = (0x01 | (MX_ADC_CONV_SP << 6)) | (MX_ADC_CHANNEL << 3);

		//wait the acquisition time
		cnt = 0;
		while (cnt < MX_ADC_SAMP_TIME) cnt++;

		//begin conversion and wait until it has finished
		adcon0 = adcon0 | 0x04;
		while (adcon0 & 0x04);

		//restore old tris value, and reset adc registers
		MX_ADC_TRIS_REG = old_tris;
		ansel = 0x00;
		adcon0 = 0x00;

		#undef MX_ADC_TRIS_REG
		#undef MX_ADC_TRIS_MSK
		#undef MX_ADC_SAMP_TIME
		#undef MX_ADC_CONV_SP
		#undef MX_ADC_VREF_OPT
		#undef MX_ADC_CHANNEL

}

short FCD_ADC1_ReadAsInt()
{
	
		short iRetVal;

		FCD_ADC1_SampleADC();

		iRetVal = (adresh << 2);
		iRetVal = iRetVal | (adresl >> 6);

		return (iRetVal);

}

void main()
{
	//a fuzzifier program that takes category information:
	//lowval, midval and highval and category name
	//and fuzzifies an input based on
	//the total number of categories and the membership in each category

	unsigned char i, j, count, maxindex, maxcounter;
    unsigned char numcat[3]={0}, inval=1, maxvalue; //for storing number of categories for inputs temperature,level and output HeaKnob

	category * ptrInTemp[5]; //create category object for Input Temperature
    category * ptrInLevel[5]; //create category object for Input Level
    
	int t, COG, numer, denom;
	//char levelCatName[5][30] = {"XSmall", "Small", "Medium", "Large", "XLarge"};
	// char tempCatName[5][30] ={"XSmall", "Small", "Medium", "Large", "XLarge"};
	//char heatknobCatName[5][30] = {"VeryLittle", "ALittle", "AGoodAmount", "ALot", "AWholeLot"};

	unsigned char LevelRanges[5][2]={{0,2}, {1,4}, {3,7}, {6,8}, {7,10}};
	unsigned char TempRanges[5][2]={{0,20}, {10,35}, {30,75}, {60,95}, {85,125}};


	unsigned char LevelMembership[5] = {0, 0, 0, 0, 0};
	unsigned char TempMembership[5] = {0, 0, 0, 0, 0};


 	unsigned char relprob[3][5];
	unsigned char total[3]={0};
	
   for(i=0;i<5;i++) {
		ptrInLevel[i] = new category;            	
		//ptrInLevel[i]->setname(levelCatName[i]);
		l = LevelRanges[i][0];
		h = LevelRanges[i][1];
		m = (h+l)/2;
		ptrInLevel[i]->setval(h, m, l);

		ptrInTemp[i] = new category;            	
		//ptrInTemp[i]->setname(tempCatName[i]);
		//cout<<input;
		l = TempRanges[i][0];
		h = TempRanges[i][1];
		m = (h+l)/2;
		ptrInTemp[i]->setval(h, m, l);

		ptrOutHeatKnob[i] = new category;            	
		//ptrOutHeatKnob[i]->setname(heatknobCatName[i]);
		l = KnobRanges[i][0];
		h = KnobRanges[i][1];
		m = (h+l)/2;
		ptrOutHeatKnob[i]->setval(h, m, l);
	}
		numcat[0] = i; //number of categories
		numcat[1] = i; //number of categories
		numcat[2] = i; //number of categories
		
	//Initialisation
	ansel = 0;
	cmcon = 0x07;

	//Interrupt initialisation code
	option_reg = 0xC0;

	while(1) {
	
	trisb = 0x00;
	portb = 0;
	//Delay: 500 ms
	delay_ms(255);
	delay_ms(245);

	for(count=0;count<3;count++) {
  
	   if(count==0){
			//cout << "\ninput a data value for Level\n";
		    //Call Component Macro: in2=ADC(1)::ReadAsInt
			FCV_IN2 = FCD_ADC1_ReadAsInt(); //Level reading simulation by Potentiometer
			inval = (FCV_IN2 * 10) / 1024; //10 bit ADC result 
		
			if(inval<=0 || inval>=10) {
				count--;
				continue;
			}

			//calculate relative probabilities of input being in each category
			total[count]=0;
	   }
	   else if(count==1){
			//cout << "\ninput a data value for Temperature\n";	
		    //Call Component Macro: in1=ADC(0)::ReadAsInt
				FCV_IN1 = FCD_ADC0_ReadAsInt(); //temperature reading simulation by LDR
				inval = (FCV_IN1 * 125) / 1024; //scale up 0-125 for reading 0-255 //10 bit ADC result 
			
				if(inval<=0 || inval>=125) {
					count--;
					continue;
				}

				//calculate relative probabilities of input being in each category
				total[count]=0;
	   }		   

			for(j=0;j<numcat[count];j++) {
         		if(count==0) {
					relprob[count][j] = ptrInLevel[j]->getshare(inval);
					total[count] += relprob[count][j];
				}
				else if(count==1) {            	
					relprob[count][j] = ptrInTemp[j]->getshare(inval);
         			total[count] += relprob[count][j];
				}				
			}
			
			if(count==0 || count==1) {

				if(total[count]==0) {
					//cout << "data out of range\n";
         			return;//exit(0);
					//goto point;
					//flag=0;
				}

			} 

			 if(count==0) {
					for(j=0;j<numcat[count];j++) {
						LevelMembership[j] = (100*relprob[count][j])/total[count];
         				//cout << ptrInLevel[j]->getname()<<"\t\t"<<(LevelMembership[j])<<"\n";					
					}	
			 }
			 else if(count==1) {         	
					for(j=0;j<numcat[count];j++) {
						TempMembership[j] = (100*relprob[count][j])/total[count];
         				//cout << ptrInTemp[j]->getname()<<"\t\t"<<(TempMembership[j])<<"\n";
					}
			 }
			 else if(count==2) {
         			
					pointCounter=0;

					/*Rule Base for Knob membership*/
					if(TempMembership[0] && LevelMembership[0])
					/*
					If SenseTemp is XSmall and SenseLevel is XSmall then set HeatKnob to AGoodAmount
					*/
					{
						setRule(2, TempMembership[0], LevelMembership[0]);	

					}
					if(TempMembership[0] && LevelMembership[1])
					/*
					If SenseTemp is XSmall and SenseLevel is Small then set HeatKnob to ALot
					*/
					{
						setRule(3, TempMembership[0], LevelMembership[1]);
											
					}
					if(TempMembership[0] && LevelMembership[2])
					/*
					If SenseTemp is XSmall and SenseLevel is Medium then set HeatKnob to AWholeLot
					*/
					{
						setRule(4, TempMembership[0], LevelMembership[2]);
						
					}
					if(TempMembership[0] && LevelMembership[3])
					/*
					If SenseTemp is XSmall and SenseLevel is Large then set HeatKnob to AWholeLot
					*/
					{
						setRule(4, TempMembership[0], LevelMembership[3]);

					}
					if(TempMembership[0] && LevelMembership[4])
					/*
					If SenseTemp is XSmall and SenseLevel is XLarge then set HeatKnob to AWholeLot
					*/
					{
						setRule(4, TempMembership[0], LevelMembership[4]);
						

					}
					if(TempMembership[1] && LevelMembership[0])
					/*
					If SenseTemp is Small and SenseLevel is XSmall then set HeatKnob to ALittle
					*/
					{
						setRule(1, TempMembership[1], LevelMembership[0]);
						
					}
					if(TempMembership[1] && LevelMembership[1])
					/*
					If SenseTemp is Small and SenseLevel is Small then set HeatKnob to AGoodAmount
					*/
					{
						setRule(2, TempMembership[1], LevelMembership[1]);
						

					}
					if(TempMembership[1] && LevelMembership[2])
					/*
					If SenseTemp is Small and SenseLevel is Medium then set HeatKnob to ALot
					*/
					{
						setRule(3, TempMembership[1], LevelMembership[2]);
						

					}
					if(TempMembership[1] && LevelMembership[3])
					/*
					If SenseTemp is Small and SenseLevel is Large then set HeatKnob to ALot
					*/
					{
						setRule(3, TempMembership[1], LevelMembership[3]);
						

					}
					if(TempMembership[1] && LevelMembership[4])
					/*
					If SenseTemp is Small and SenseLevel is XLarge then set HeatKnob to ALot
					*/
					{
						setRule(3, TempMembership[1], LevelMembership[4]);
					
					}
					if(TempMembership[2] && LevelMembership[0])
					/*
					If SenseTemp is Medium and SenseLevel is XSmall then set HeatKnob to VeryLittle
					*/
					{
						setRule(0, TempMembership[2], LevelMembership[0]);
						

					}
					if(TempMembership[2] && LevelMembership[1])
					/*
					If SenseTemp is Medium and SenseLevel is Small then set HeatKnob to VeryLittle
					*/
					{
						setRule(0, TempMembership[2], LevelMembership[1]);
						
					}
					if(TempMembership[2] && LevelMembership[2])
					/*
					If SenseTemp is Medium and SenseLevel is Medium then set HeatKnob to AGoodAmount
					*/
					{
						setRule(2, TempMembership[2], LevelMembership[2]);
						
					}
					if(TempMembership[2] && LevelMembership[3])
					/*
					If SenseTemp is Medium and SenseLevel is Large then set HeatKnob to ALot
					*/
					{
						setRule(3, TempMembership[2], LevelMembership[3]);
						

					}
					if(TempMembership[2] && LevelMembership[4])
					/*
					If SenseTemp is Medium and SenseLevel is XLarge then set HeatKnob to ALot
					*/
					{
						setRule(3, TempMembership[2], LevelMembership[4]);
						

					}
					if(TempMembership[3] && LevelMembership[1])
					/*
					If SenseTemp is Large and SenseLevel is Small then set HeatKnob to VeryLittle
					*/
					{
						setRule(0, TempMembership[3], LevelMembership[1]);						

					}
					if(TempMembership[3] && LevelMembership[2])
					/*
					If SenseTemp is Large and SenseLevel is Medium then set HeatKnob to VeryLittle
					*/
					{
						setRule(0, TempMembership[3], LevelMembership[2]);
						
					}
					if(TempMembership[3] && LevelMembership[3])
					/*
					If SenseTemp is Large and SenseLevel is Large then set HeatKnob to ALittle
					*/
					{
						setRule(1, TempMembership[3], LevelMembership[3]);
						
					}
					if(TempMembership[3] && LevelMembership[4])
					/*
					If SenseTemp is Large and SenseLevel is XLarge then set HeatKnob to AGoodAmount
					*/
					{
						setRule(2, TempMembership[3], LevelMembership[4]);						
					}

					//cout<<"\nHeatKnob Membership Output based on Rule Base:\n";
					maxvalue=0;
					//defuzzify
					for(j=0;j<numcat[count];j++) {
						//cout<<ptrOutHeatKnob[j]->getname()<<' '<<knobMembership[j]<<'\n';
						if(knobMembership[j] > maxvalue) {
							maxvalue = knobMembership[j];
							maxindex = j;
						}
					}
						if(maxvalue) {
							l = KnobRanges[maxindex][0];
							h = KnobRanges[maxindex][1];
							maxvalue = ((h-l)*maxvalue)/100+l;
							//cout<<"\nDefuzzified value based on Centre of Maximum: "<<maxvalue<<"\n";
							if(maxvalue>0 && maxvalue<=10) {															
								//Output: out -> PORT B
								trisb = 0x00;
								portb = maxvalue;				
				
								delay_ms(255);
								delay_ms(245);
						
								//Output: 0 -> PORT B
								trisb = 0x00;
								portb = 0;
							}
						}
						insertion_sort(defuzzXpoints, pointCounter); //ascending order sort defuzzXpoints
						insertion_sort(defuzzYpoints, pointCounter); //ascending order sort defuzzYpoints
	
						if(pointCounter<2) COG = 0;
						numer = denom = 0;
	
						for(i=1;i<pointCounter;i++) {
							//cout<<defuzzXpoints[i]<<'\t'<<defuzzYpoints[i]<<'\n';
							t = defuzzYpoints[i-1] * (2 * defuzzXpoints[i-1] + defuzzXpoints[i]) + defuzzYpoints[i] * (defuzzXpoints[i-1] + 2 * defuzzXpoints[i]);
							numer += t * (defuzzXpoints[i] - defuzzXpoints[i-1]);
							denom += (defuzzXpoints[i] - defuzzXpoints[i-1]) * (defuzzYpoints[i-1] + defuzzYpoints[i]);
						}
						if(denom) COG = numer / (3 * denom);
						//cout<<"Defuzzified value with Centre of Gravity: "<<COG<<"\n";
						if(COG) {
							//Output: out -> PORT B
								trisb = 0x00;
								portb = COG;				
				
								delay_ms(255);
								delay_ms(245);
						
								//Output: 0 -> PORT B
								trisb = 0x00;
								portb = 0;
						}
			 }
		}
   }

}

Following changes are made in the code for reading potentiometer values 0-1024 and transmitting these both to Level, Temperature and scaling these for 0-10 and 0-125 respectively.

	for(count=0;count<3;count++) {
  
	   if(count==0){
			//cout << "\ninput a data value for Level\n";
		    //Call Component Macro: in2=ADC(1)::ReadAsInt
			
			//FCV_IN1 = FCD_ADC0_ReadAsInt();
			//inval = (FCV_IN1 * 10) / 1024; 
			FCV_IN1 = FCD_ADC1_ReadAsInt(); //Level reading simulation by Potentiometer
			inval = (FCV_IN1 * 10) / 1024; //10 bit ADC result scaled for 0-10 
				
			
			//inval=1;
			if(inval<=0 || inval>=10) {
				count--;
				continue;
			}

			
			//Output: in2 -> PORT B
			trisb = 0x00;
			portb = inval;
	
			//Delay: 500 ms
			delay_ms(255);
			delay_ms(245);
	
			//Output: 0 -> PORT B
			trisb = 0x00;
			portb = 0;
			
			//calculate relative probabilities of input being in each category
			total[count]=0;
	   }
	   else if(count==1){
			//cout << "\ninput a data value for Temperature\n";	
		    //Call Component Macro: in1=ADC(0)::ReadAsInt
		    
		    FCV_IN2 = FCD_ADC1_ReadAsInt(); //Temperature reading simulation by Potentiometer
			inval = (FCV_IN2 * 125) / 1024; //10 bit ADC result scaled for 0-125
				
				//inval=1;
				if(inval<=0 || inval>=125) {
					count--;
					continue;
				}

				
				//Output: in1 -> PORT B
				trisb = 0x00;
				portb = inval;
		
				//Delay: 500 ms
				delay_ms(255);
				delay_ms(245);
		
				//Output: 0 -> PORT B
				trisb = 0x00;
				portb = 0;
				
				//calculate relative probabilities of input being in each category
				total[count]=0;
	   }		
