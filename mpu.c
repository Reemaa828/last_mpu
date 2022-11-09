#include "mpu.h"
#include "I2C.h"
#include "STD_Types.h"
#include "MACROS.h"
/************************************************************************/
/*							Function definitions                        */
/************************************************************************/

void ERROR_CHECK(ret_code_t error_code)
{
	if (error_code != SUCCESS)
	{
		/* Print error code and loop indefinitely until reset */
		// printf(BR "App error! error_code = 0x%02X\n" RESET, error_code);
		while (1); // loop indefinitely
	}
}

void mpu_init(void)
{    ret_code_t error_code;
	// puts("Write 0 to PWR_MGMT_1 reg to wakeup MPU.");
	u8 data[2] = {PWR_MGMT_1, 0};
	error_code = tw_master_transmit(MPU6050_ADDR, data, sizeof(data), false);
	ERROR_CHECK(error_code);

}

void mpu_get_accel_raw(mpu_data_t* mpu_data)
{
    ret_code_t error_code;
	/* 2 registers for each of accel x, y and z data */
	u8 data[6];
	
	data[0] = ACCEL_XOUT_H;
	error_code = tw_master_transmit(MPU6050_ADDR, data, 1, true);
	ERROR_CHECK(error_code);
	
	error_code = tw_master_receive(MPU6050_ADDR, data, sizeof(data));
	ERROR_CHECK(error_code);
	/* Default accel config +/- 2g */
	mpu_data->x = (s16)(data[0] << 8 | data[1]) / 16384.0;
	mpu_data->y = (s16)(data[2] << 8 | data[3]) / 16384.0;
	mpu_data->z = (s16)(data[4] << 8 | data[5]) / 16384.0;
}

void mpu_get_gyro_raw(mpu_data_t *mpu_data){
 ret_code_t error_code;
	/* 2 registers for each of accel x, y and z data */
	u8 data[6];
	
	data[0] = GYRO_XOUT_H;
	error_code = tw_master_transmit(MPU6050_ADDR, data, 1, true);
	ERROR_CHECK(error_code);
	
	error_code = tw_master_receive(MPU6050_ADDR, data, sizeof(data));
	ERROR_CHECK(error_code);
	/* Default accel config +/- 2g */
	mpu_data->x = (s16)(data[0] << 8 | data[1]) / 16.4;
	mpu_data->y = (s16)(data[2] << 8 | data[3]) / 16.4;
	mpu_data->z = (s16)(data[4] << 8 | data[5]) / 16.4;
}

void mpu_get_gyro(mpu_data_t *mpu_data){
   mpu_get_gyro_raw(mpu_data);
	mpu_data->x = mpu_data->x ;
	mpu_data->y = mpu_data->y ;
	mpu_data->z = mpu_data->z ;
}

void mpu_get_accel(mpu_data_t* mpu_data)
{
	mpu_get_accel_raw(mpu_data);
	mpu_data->x = mpu_data->x * 9.81;
	mpu_data->y = mpu_data->y * 9.81;
	mpu_data->z = mpu_data->z * 9.81;
}

