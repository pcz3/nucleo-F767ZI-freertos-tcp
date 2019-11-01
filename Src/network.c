/*******************************************************************************
 * @attention Copyright would go here...
 * @file network.c
 * @author Paul Czeresko
 * @date 01 Nov 2019
 * @brief Network tasks and hooks for TCP/IP operation
 *******************************************************************************/

#include "network.h"
#include "FreeRTOS.h"

void vApplicationIPNetworkEventHook( eIPCallbackEvent_t eNetworkEvent )
{
	static BaseType_t xTasksAlreadyCreated = pdFALSE;

	/* Both eNetworkUp and eNetworkDown events can be processed here. */
	if( eNetworkEvent == eNetworkUp )
	{
		/* Create the tasks that use the TCP/IP stack if they have not already
        been created. */
		if( xTasksAlreadyCreated == pdFALSE )
		{
			/*
			 * For convenience, tasks that use FreeRTOS+TCP can be created here
			 * to ensure they are not created before the network is usable.
			 */

			xTasksAlreadyCreated = pdTRUE;
		}
	}
}
