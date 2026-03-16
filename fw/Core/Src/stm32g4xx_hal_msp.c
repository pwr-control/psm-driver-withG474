/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file         stm32g4xx_hal_msp.c
  * @brief        This file provides code for the MSP Initialization
  *               and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_HandleTypeDef hdma_adc1;

extern DMA_HandleTypeDef hdma_adc2;

extern DMA_HandleTypeDef hdma_hrtim1_a;

extern DMA_HandleTypeDef hdma_hrtim1_b;

extern DMA_HandleTypeDef hdma_hrtim1_e;

extern DMA_HandleTypeDef hdma_hrtim1_f;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

void HAL_HRTIM_MspPostInit(HRTIM_HandleTypeDef *hhrtim);
                    /**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{

  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /** Disable the internal Pull-Up in Dead Battery pins of UCPD peripheral
  */
  HAL_PWREx_DisableUCPDDeadBattery();

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

static uint32_t HAL_RCC_ADC12_CLK_ENABLED=0;

/**
  * @brief ADC MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hadc->Instance==ADC1)
  {
    /* USER CODE BEGIN ADC1_MspInit 0 */

    /* USER CODE END ADC1_MspInit 0 */

  /** Initializes the peripherals clocks
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC12;
    PeriphClkInit.Adc12ClockSelection = RCC_ADC12CLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    HAL_RCC_ADC12_CLK_ENABLED++;
    if(HAL_RCC_ADC12_CLK_ENABLED==1){
      __HAL_RCC_ADC12_CLK_ENABLE();
    }

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**ADC1 GPIO Configuration
    PC0     ------> ADC1_IN6
    PC1     ------> ADC1_IN7
    PC3     ------> ADC1_IN9
    PA0     ------> ADC1_IN1
    PA1     ------> ADC1_IN2
    PB12     ------> ADC1_IN11
    PB14     ------> ADC1_IN5
    */
    GPIO_InitStruct.Pin = ugw_Pin|udc_Pin|ugu_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = isu_Pin|isv_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = isw_Pin|ugv_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* ADC1 DMA Init */
    /* ADC1 Init */
    hdma_adc1.Instance = DMA1_Channel1;
    hdma_adc1.Init.Request = DMA_REQUEST_ADC1;
    hdma_adc1.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_adc1.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_adc1.Init.MemInc = DMA_MINC_ENABLE;
    hdma_adc1.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_adc1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_adc1.Init.Mode = DMA_CIRCULAR;
    hdma_adc1.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_adc1) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hadc,DMA_Handle,hdma_adc1);

    /* USER CODE BEGIN ADC1_MspInit 1 */

    /* USER CODE END ADC1_MspInit 1 */
  }
  else if(hadc->Instance==ADC2)
  {
    /* USER CODE BEGIN ADC2_MspInit 0 */

    /* USER CODE END ADC2_MspInit 0 */

  /** Initializes the peripherals clocks
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC12;
    PeriphClkInit.Adc12ClockSelection = RCC_ADC12CLKSOURCE_SYSCLK;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    HAL_RCC_ADC12_CLK_ENABLED++;
    if(HAL_RCC_ADC12_CLK_ENABLED==1){
      __HAL_RCC_ADC12_CLK_ENABLE();
    }

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**ADC2 GPIO Configuration
    PC2     ------> ADC2_IN8
    PA6     ------> ADC2_IN3
    PA7     ------> ADC2_IN4
    PC4     ------> ADC2_IN5
    PC5     ------> ADC2_IN11
    PB2     ------> ADC2_IN12
    PB11     ------> ADC2_IN14
    */
    GPIO_InitStruct.Pin = tu_Pin|tv_Pin|tw_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = igu_Pin|igv_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = igw_Pin|ta_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* ADC2 DMA Init */
    /* ADC2 Init */
    hdma_adc2.Instance = DMA1_Channel2;
    hdma_adc2.Init.Request = DMA_REQUEST_ADC2;
    hdma_adc2.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_adc2.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_adc2.Init.MemInc = DMA_MINC_ENABLE;
    hdma_adc2.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_adc2.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_adc2.Init.Mode = DMA_CIRCULAR;
    hdma_adc2.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_adc2) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hadc,DMA_Handle,hdma_adc2);

    /* USER CODE BEGIN ADC2_MspInit 1 */

    /* USER CODE END ADC2_MspInit 1 */
  }

}

/**
  * @brief ADC MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc)
{
  if(hadc->Instance==ADC1)
  {
    /* USER CODE BEGIN ADC1_MspDeInit 0 */

    /* USER CODE END ADC1_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_ADC12_CLK_ENABLED--;
    if(HAL_RCC_ADC12_CLK_ENABLED==0){
      __HAL_RCC_ADC12_CLK_DISABLE();
    }

    /**ADC1 GPIO Configuration
    PC0     ------> ADC1_IN6
    PC1     ------> ADC1_IN7
    PC3     ------> ADC1_IN9
    PA0     ------> ADC1_IN1
    PA1     ------> ADC1_IN2
    PB12     ------> ADC1_IN11
    PB14     ------> ADC1_IN5
    */
    HAL_GPIO_DeInit(GPIOC, ugw_Pin|udc_Pin|ugu_Pin);

    HAL_GPIO_DeInit(GPIOA, isu_Pin|isv_Pin);

    HAL_GPIO_DeInit(GPIOB, isw_Pin|ugv_Pin);

    /* ADC1 DMA DeInit */
    HAL_DMA_DeInit(hadc->DMA_Handle);
    /* USER CODE BEGIN ADC1_MspDeInit 1 */

    /* USER CODE END ADC1_MspDeInit 1 */
  }
  else if(hadc->Instance==ADC2)
  {
    /* USER CODE BEGIN ADC2_MspDeInit 0 */

    /* USER CODE END ADC2_MspDeInit 0 */
    /* Peripheral clock disable */
    HAL_RCC_ADC12_CLK_ENABLED--;
    if(HAL_RCC_ADC12_CLK_ENABLED==0){
      __HAL_RCC_ADC12_CLK_DISABLE();
    }

    /**ADC2 GPIO Configuration
    PC2     ------> ADC2_IN8
    PA6     ------> ADC2_IN3
    PA7     ------> ADC2_IN4
    PC4     ------> ADC2_IN5
    PC5     ------> ADC2_IN11
    PB2     ------> ADC2_IN12
    PB11     ------> ADC2_IN14
    */
    HAL_GPIO_DeInit(GPIOC, tu_Pin|tv_Pin|tw_Pin);

    HAL_GPIO_DeInit(GPIOA, igu_Pin|igv_Pin);

    HAL_GPIO_DeInit(GPIOB, igw_Pin|ta_Pin);

    /* ADC2 DMA DeInit */
    HAL_DMA_DeInit(hadc->DMA_Handle);
    /* USER CODE BEGIN ADC2_MspDeInit 1 */

    /* USER CODE END ADC2_MspDeInit 1 */
  }

}

/**
  * @brief FDCAN MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hfdcan: FDCAN handle pointer
  * @retval None
  */
void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* hfdcan)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(hfdcan->Instance==FDCAN1)
  {
    /* USER CODE BEGIN FDCAN1_MspInit 0 */

    /* USER CODE END FDCAN1_MspInit 0 */

  /** Initializes the peripherals clocks
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN;
    PeriphClkInit.FdcanClockSelection = RCC_FDCANCLKSOURCE_PCLK1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* Peripheral clock enable */
    __HAL_RCC_FDCAN_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PA12     ------> FDCAN1_TX
    PB8-BOOT0     ------> FDCAN1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* USER CODE BEGIN FDCAN1_MspInit 1 */

    /* USER CODE END FDCAN1_MspInit 1 */

  }

}

/**
  * @brief FDCAN MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hfdcan: FDCAN handle pointer
  * @retval None
  */
void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* hfdcan)
{
  if(hfdcan->Instance==FDCAN1)
  {
    /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

    /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_FDCAN_CLK_DISABLE();

    /**FDCAN1 GPIO Configuration
    PA12     ------> FDCAN1_TX
    PB8-BOOT0     ------> FDCAN1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_12);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8);

    /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

    /* USER CODE END FDCAN1_MspDeInit 1 */
  }

}

/**
  * @brief HRTIM MSP Initialization
  * This function configures the hardware resources used in this example
  * @param hhrtim: HRTIM handle pointer
  * @retval None
  */
void HAL_HRTIM_MspInit(HRTIM_HandleTypeDef* hhrtim)
{
  if(hhrtim->Instance==HRTIM1)
  {
    /* USER CODE BEGIN HRTIM1_MspInit 0 */

    /* USER CODE END HRTIM1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_HRTIM1_CLK_ENABLE();

    /* HRTIM1 DMA Init */
    /* HRTIM1_A Init */
    hdma_hrtim1_a.Instance = DMA1_Channel3;
    hdma_hrtim1_a.Init.Request = DMA_REQUEST_HRTIM1_A;
    hdma_hrtim1_a.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_hrtim1_a.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_hrtim1_a.Init.MemInc = DMA_MINC_ENABLE;
    hdma_hrtim1_a.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_hrtim1_a.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_hrtim1_a.Init.Mode = DMA_NORMAL;
    hdma_hrtim1_a.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_hrtim1_a) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hhrtim,hdmaTimerA,hdma_hrtim1_a);

    /* HRTIM1_B Init */
    hdma_hrtim1_b.Instance = DMA1_Channel4;
    hdma_hrtim1_b.Init.Request = DMA_REQUEST_HRTIM1_B;
    hdma_hrtim1_b.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_hrtim1_b.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_hrtim1_b.Init.MemInc = DMA_MINC_ENABLE;
    hdma_hrtim1_b.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_hrtim1_b.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_hrtim1_b.Init.Mode = DMA_NORMAL;
    hdma_hrtim1_b.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_hrtim1_b) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hhrtim,hdmaTimerB,hdma_hrtim1_b);

    /* HRTIM1_E Init */
    hdma_hrtim1_e.Instance = DMA1_Channel5;
    hdma_hrtim1_e.Init.Request = DMA_REQUEST_HRTIM1_E;
    hdma_hrtim1_e.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_hrtim1_e.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_hrtim1_e.Init.MemInc = DMA_MINC_ENABLE;
    hdma_hrtim1_e.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_hrtim1_e.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_hrtim1_e.Init.Mode = DMA_NORMAL;
    hdma_hrtim1_e.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_hrtim1_e) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hhrtim,hdmaTimerE,hdma_hrtim1_e);

    /* HRTIM1_F Init */
    hdma_hrtim1_f.Instance = DMA1_Channel6;
    hdma_hrtim1_f.Init.Request = DMA_REQUEST_HRTIM1_F;
    hdma_hrtim1_f.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_hrtim1_f.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_hrtim1_f.Init.MemInc = DMA_MINC_ENABLE;
    hdma_hrtim1_f.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
    hdma_hrtim1_f.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_hrtim1_f.Init.Mode = DMA_NORMAL;
    hdma_hrtim1_f.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_hrtim1_f) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hhrtim,hdmaTimerF,hdma_hrtim1_f);

    /* USER CODE BEGIN HRTIM1_MspInit 1 */

    /* USER CODE END HRTIM1_MspInit 1 */

  }

}

void HAL_HRTIM_MspPostInit(HRTIM_HandleTypeDef* hhrtim)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hhrtim->Instance==HRTIM1)
  {
    /* USER CODE BEGIN HRTIM1_MspPostInit 0 */

    /* USER CODE END HRTIM1_MspPostInit 0 */

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**HRTIM1 GPIO Configuration
    PC6     ------> HRTIM1_CHF1
    PC7     ------> HRTIM1_CHF2
    PC8     ------> HRTIM1_CHE1
    PC9     ------> HRTIM1_CHE2
    PA8     ------> HRTIM1_CHA1
    PA9     ------> HRTIM1_CHA2
    PA10     ------> HRTIM1_CHB1
    PA11     ------> HRTIM1_CHB2
    */
    GPIO_InitStruct.Pin = phw_top_Pin|phw_bot_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF13_HRTIM1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = phn_top_Pin|phn_bot_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF3_HRTIM1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = phu_top_Pin|phu_bot_Pin|phv_top_Pin|phv_bot_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF13_HRTIM1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* USER CODE BEGIN HRTIM1_MspPostInit 1 */

    /* USER CODE END HRTIM1_MspPostInit 1 */
  }

}
/**
  * @brief HRTIM MSP De-Initialization
  * This function freeze the hardware resources used in this example
  * @param hhrtim: HRTIM handle pointer
  * @retval None
  */
void HAL_HRTIM_MspDeInit(HRTIM_HandleTypeDef* hhrtim)
{
  if(hhrtim->Instance==HRTIM1)
  {
    /* USER CODE BEGIN HRTIM1_MspDeInit 0 */

    /* USER CODE END HRTIM1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_HRTIM1_CLK_DISABLE();

    /* HRTIM1 DMA DeInit */
    HAL_DMA_DeInit(hhrtim->hdmaTimerA);
    HAL_DMA_DeInit(hhrtim->hdmaTimerB);
    HAL_DMA_DeInit(hhrtim->hdmaTimerE);
    HAL_DMA_DeInit(hhrtim->hdmaTimerF);
    /* USER CODE BEGIN HRTIM1_MspDeInit 1 */

    /* USER CODE END HRTIM1_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
