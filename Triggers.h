#ifndef __TRIGGERS_H__
#define __TRIGGERS_H__

#include <iostream>
#include <string>

#define N_signals 11

using namespace std;

string BadSignalToGoodSignal(string signal);
string GoodSignalToBadSignal(string signal);

void RS_asynchrony_trigger(string R_signal, string S_signal);
void RS_synchrony_trigger(string R_signal, string S_signal, string C_signal, char first_Q);
void D_trigger(string D_signal, string C_signal, char first_Q);
void JK_trigger(string J_signal, string K_signal, string C_signal, char first_Q);
void T_trigger(string T_signal, string C_signal, char first_Q);

#endif // __TRIGGERS_H__
