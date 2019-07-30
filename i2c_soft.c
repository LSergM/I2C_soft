/**
 * i2c_soft.h
 *
 * Created on: 37. aug. 2019
 * Author: SLOZ
 *
 * @version 0.0.1
 * bugs:  
 */
 
 #include "i2c_soft.h"
 
 /**
 * @brief Write data over I2C bus
  *
 * @param [in] u8Data_out       : data for sending over an I2C bus
 *
 * @author SLOZ
 * @date   30-07-2019
 * @version 0.0.1
 */
 void vI2C_write(uint8_t u8Data_out)  
{
      Short_Delay(1);
      for (uint8_t n=0; n<8; n++) 
      {                
         if(Data_out & 0x80){           
         SDA_UP;      // отпустил SDA в "1"
         while(!SDA); // ждёт освобождения SDA в "1"   
         }
         else {  
         SDA_DOWN; // SDA в "0"        
         } 
  
         Short_Delay(1);
         
         SCL_UP;      // отпустил SCL в "1"
         while(!SCL); // ждёт освобождения SCL в "1"
         Short_Delay(1);
         
         SCL_DOWN; // SCL в "0"
         Short_Delay(1);
         
         Data_out <<= 1;   //  сдвиг влево         
      }
      
      SDA_UP;     // отпустил SDA в "1"  
      Short_Delay(1);
      SCL_UP;      // отпустил SCL в "1"
      while(!SCL); // ждёт освобождения SCL в "1"
      Short_Delay(1);
      
      
      if(SDA){   // читает состояние SDA       
         Error = 1;  // нет подтверждения ACK
         }
         else {  
         Error = 0;  // есть подтверждение ACK   
         } 
      
      SCL_DOWN; // SCL в "0"
      Short_Delay(1);
      SDA_DOWN; // SDA в "0"
      Short_Delay(1);
}

 /**
 * @brief Read data from I2C bus
  *
 * @param [in] u8Ack_NoAck :     
 * @return				   : data read from an I2C bus
 *
 * @author SLOZ
 * @date   30-07-2019
 * @version 0.0.1
 */
uint8_t u8I2C_read(uint8_t u8Ack_NoAck) 
{  
      uint8_t Data_in = 0;

      Short_Delay(1);
           
      for (uint8_t n=0; n<8; n++) 
      {       
        Data_in <<= 1;
        
        SDA_UP;  // отпустил SDA в "1"
        Short_Delay(1);
        
        SCL_UP;      // отпустил SCL в "1"
        while(!SCL); // ждёт освобождения SCL в "1"
        Short_Delay(1);
        
        Data_in |= SDA;   // читает состояние SDA
        
        SCL_DOWN; // SCL в "0"
        Short_Delay(1);
      }

      if(!Ack_NoAck){  // ACK          
                  
        SDA_DOWN; // SDA в "0"
        Short_Delay(1);
        
        SCL_UP;  // отпустил SCL в "1"
        while(!SCL); // ждёт освобождения SCL в "1"
        Short_Delay(1);
           
        SCL_DOWN; // SCL в "0"
        Short_Delay(1);
        
      }   
      else {  // NACK ЭТОТ БАЙТ ПРИНИМАЕТСЯ ПОСЛЕДНИМ
        
        SDA_UP;  // отпустил SDA в "1"
        while(!SDA); // ждёт освобождения SDA в "1"  
        Short_Delay(1);
        
        SCL_UP;  // отпустил SCL в "1"
        while(!SCL); // ждёт освобождения SCL в "1"
        Short_Delay(1);
           
        SCL_DOWN; // SCL в "0"
        Short_Delay(1);
        
        SDA_DOWN; // SDA в "0"
        Short_Delay(1);                
      } 
      
return(Data_in); 
}

/**
 * @brief Short delay
  *
 * @param [in] u32Delay_time : Value of delay    
 *
 * @author SLOZ
 * @date   30-07-2019
 * @version 0.0.1
 */
void vShort_Delay(volatile uint32_t u32Delay_time)  
{
  while(u32Delay_time > 0)
  {
	u32Delay_time--;  
  }
}