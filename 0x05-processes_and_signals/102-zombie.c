/*
 *  * File: zombie.c
 *   */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 *  * infinite_while - This runs an infinite while loop.
 *   *
 *    * Return: always 0.
 *     */
int infinite_while(void)
{
		while (1)
				{
							sleep(1);
								}
			return (0);
}

/**
 *  * main - this creates 5 zombie processes.
 *   *
 *    * Return: Always 0.
 *     */
int main(void)
{
		pid_t pid_;
			char count_ = 0;

				while (count_ < 5)
						{
									pid_ = fork();
											if (pid_ > 0)
														{
																		printf("Zombie process created, PID: %d\n", pid_);
																					sleep(1);
																								count_++;
																										}
													else
																	exit(0);
														}

					infinite_while();

						return (EXIT_SUCCESS);
}

