#include "Triggers.h"

string BadSignalToGoodSignal(string signal)
{
    string Signal;
    char LastSignal = '0';
    for (int i = 0; i < N_signals; i++)
    {
        if (signal[i] == '1')
        {
            Signal += '1';
            LastSignal = '1';
        }
        else if (signal[i] == '0')
        {
            Signal += '0';
            LastSignal = '0';
        }
        else if (signal[i] == '.')
            Signal += LastSignal;
    }
    return Signal;
}

string GoodSignalToBadSignal(string signal)
{
    string Signal;
    char LastSignal = '-';

    for (int i = 0; i < N_signals; i++)
    {
        if (signal[i] == '1')
        {
            if (LastSignal == '1') Signal += '.';
            else Signal += '1';
            LastSignal = '1';
        }
        else if (signal[i] == '0')
        {
            if (LastSignal == '0') Signal += '.';
            else Signal += '0';
            LastSignal = '0';
        }
    }

    return Signal;
}

void RS_asynchrony_trigger(string R_signal, string S_signal)
{
    char LastSignal;
    string signal_Q;
    R_signal = BadSignalToGoodSignal(R_signal);
    S_signal = BadSignalToGoodSignal(S_signal);

    for (int i = 0; i < N_signals; i++)
    {
        if (R_signal[i] == S_signal[i])
            signal_Q += LastSignal;
        else
        {
            signal_Q += S_signal[i];
            LastSignal = S_signal[i];
        }
    }

    signal_Q = GoodSignalToBadSignal(signal_Q);
    cout << "\nQ " << signal_Q << "\n";
}

void RS_synchrony_trigger(string R_signal, string S_signal, string C_signal, char first_Q)
{
    char LastSignal1 = first_Q, LastSignal2 = first_Q, LastSignal3 = first_Q, LastSignal4 = first_Q;
    string static_direct_Q, static_invert_Q, dynamic_direct_Q, dynamic_invert_Q;
    R_signal = BadSignalToGoodSignal(R_signal);
    S_signal = BadSignalToGoodSignal(S_signal);
    C_signal = BadSignalToGoodSignal(C_signal);

    dynamic_direct_Q += first_Q;
    dynamic_invert_Q += first_Q;

    for (int i = 0; i < N_signals; i++)
    {
        // static_direct_Q
        if (C_signal[i] == '1')
        {
            if (R_signal[i] == S_signal[i])
                static_direct_Q += LastSignal1;
            else
            {
                static_direct_Q += S_signal[i];
                LastSignal1 = S_signal[i];
            }
        }
        else static_direct_Q += LastSignal1;

        // static_invert_Q
        if (C_signal[i] == '0')
        {
            if (R_signal[i] == S_signal[i])
                static_invert_Q += LastSignal2;
            else
            {
                static_invert_Q += S_signal[i];
                LastSignal2 = S_signal[i];
            }
        }
        else static_invert_Q += LastSignal2;

        // dynamic_direct_Q
        if (i > 0)
        {
            if (C_signal[i] == '1' && C_signal[i - 1] == '0')
            {
                if (R_signal[i - 1] == S_signal[i - 1])
                    dynamic_direct_Q += LastSignal3;
                else
                {
                    dynamic_direct_Q += S_signal[i - 1];
                    LastSignal3 = S_signal[i - 1];
                }
            }
            else dynamic_direct_Q += LastSignal3;
        }

        // dynamic_invert_Q
        if (i > 0)
        {
            if (C_signal[i] == '0' && C_signal[i - 1] == '1')
            {
                if (R_signal[i - 1] == S_signal[i - 1])
                    dynamic_invert_Q += LastSignal4;
                else
                {
                    dynamic_invert_Q += S_signal[i - 1];
                    LastSignal4 = S_signal[i - 1];
                }
            }
            else dynamic_invert_Q += LastSignal4;
        }
    }

    static_direct_Q = GoodSignalToBadSignal(static_direct_Q);
    static_invert_Q = GoodSignalToBadSignal(static_invert_Q);
    dynamic_direct_Q = GoodSignalToBadSignal(dynamic_direct_Q);
    dynamic_invert_Q = GoodSignalToBadSignal(dynamic_invert_Q);
    cout << "\nQ dlia priamogo statychnogo C " << static_direct_Q << "\n";
    cout << "Q dlia inversnogo statychnogo C " << static_invert_Q << "\n";
    cout << "Q dlia priamogo dynamichnogo C " << dynamic_direct_Q << "\n";
    cout << "Q dlia inversnogo dynamichnogo C " << dynamic_invert_Q << "\n";
}

void D_trigger(string D_signal, string C_signal, char first_Q)
{
    char LastSignal1 = first_Q, LastSignal2 = first_Q, LastSignal3 = first_Q, LastSignal4 = first_Q;
    string static_direct_Q, static_invert_Q, dynamic_direct_Q, dynamic_invert_Q;
    D_signal = BadSignalToGoodSignal(D_signal);
    C_signal = BadSignalToGoodSignal(C_signal);

    dynamic_direct_Q += first_Q;
    dynamic_invert_Q += first_Q;

    for (int i = 0; i < N_signals; i++)
    {
        if (C_signal[i] == '1')
        {
            static_direct_Q += D_signal[i];
            LastSignal1 = D_signal[i];
            static_invert_Q += LastSignal2;
        }
        else
        {
            static_direct_Q += LastSignal1;
            static_invert_Q += D_signal[i];
            LastSignal2 = D_signal[i];
        }

        if (i > 0)
        {
            if (C_signal[i] == '1' && C_signal[i - 1] == '0')
            {
                dynamic_direct_Q += D_signal[i - 1];
                LastSignal3 = D_signal[i - 1];
            }
            else
            {
                dynamic_direct_Q += LastSignal3;
            }

            if (C_signal[i] == '0' && C_signal[i - 1] == '1')
            {
                dynamic_invert_Q += D_signal[i - 1];
                LastSignal4 = D_signal[i - 1];
            }
            else
            {
                dynamic_invert_Q += LastSignal4;
            }
        }
    }

    static_direct_Q = GoodSignalToBadSignal(static_direct_Q);
    static_invert_Q = GoodSignalToBadSignal(static_invert_Q);
    dynamic_direct_Q = GoodSignalToBadSignal(dynamic_direct_Q);
    dynamic_invert_Q = GoodSignalToBadSignal(dynamic_invert_Q);

    cout << "\nQ dlia priamogo statychnogo C " << static_direct_Q << "\n";
    cout << "Q dlia inversnogo satychnogo C " << static_invert_Q << "\n";
    cout << "Q dlia priamogo dynamichnogo C " << dynamic_direct_Q << "\n";
    cout << "Q dlia inversnogo dynamichnogo C " << dynamic_invert_Q << "\n";
}

void JK_trigger(string J_signal, string K_signal, string C_signal, char first_Q)
{
    char LastSignal3 = first_Q, LastSignal4 = first_Q;
    string dynamic_direct_Q, dynamic_invert_Q;
    J_signal = BadSignalToGoodSignal(J_signal);
    K_signal = BadSignalToGoodSignal(K_signal);
    C_signal = BadSignalToGoodSignal(C_signal);

    dynamic_direct_Q += first_Q;
    dynamic_invert_Q += first_Q;

    for (int i = 1; i < N_signals; i++)
    {
        if (C_signal[i] == '1' && C_signal[i - 1] == '0')
        {
            if (J_signal[i - 1] == K_signal[i - 1])
            {
                if (J_signal[i - 1] == '0')
                    dynamic_direct_Q += LastSignal3;
                else if (LastSignal3 == '1')
                    dynamic_direct_Q += '0';
                else
                    dynamic_direct_Q += '1';
                LastSignal3 = dynamic_direct_Q[i];
            }
            else
            {
                dynamic_direct_Q += J_signal[i - 1];
                LastSignal3 = J_signal[i - 1];
            }
        }
        else dynamic_direct_Q += LastSignal3;

        if (C_signal[i] == '0' && C_signal[i - 1] == '1')
        {
            if (J_signal[i - 1] == K_signal[i - 1])
            {
                if (J_signal[i - 1] == '0')
                    dynamic_invert_Q += LastSignal4;
                else if (LastSignal4 == '1')
                    dynamic_invert_Q += '0';
                else
                    dynamic_invert_Q += '1';
                LastSignal4 = dynamic_invert_Q[i];
            }
            else
            {
                dynamic_invert_Q += J_signal[i - 1];
                LastSignal4 = J_signal[i - 1];
            }
        }
        else dynamic_invert_Q += LastSignal4;
    }

    dynamic_direct_Q = GoodSignalToBadSignal(dynamic_direct_Q);
    dynamic_invert_Q = GoodSignalToBadSignal(dynamic_invert_Q);
    cout << "\nQ dlia priamogo dynamichnogo C " << dynamic_direct_Q << "\n";
    cout << "Q dlia inversnogo dynamichnogo C " << dynamic_invert_Q << "\n";
}

void T_trigger(string T_signal, string C_signal, char first_Q)
{
    char LastSignal3 = first_Q, LastSignal4 = first_Q;
    string dynamic_direct_Q, dynamic_invert_Q;
    T_signal = BadSignalToGoodSignal(T_signal);
    C_signal = BadSignalToGoodSignal(C_signal);

    dynamic_direct_Q += first_Q;
    dynamic_invert_Q += first_Q;

    for (int i = 1; i < N_signals; i++)
    {
        if (C_signal[i] == '1' && C_signal[i - 1] == '0')
        {
            if (T_signal[i - 1] == '0')
                dynamic_direct_Q += LastSignal3;
            else if (LastSignal3 == '1')
            {
                dynamic_direct_Q += '0';
                LastSignal3 = '0';
            }
            else
            {
                dynamic_direct_Q += '1';
                LastSignal3 = '1';
            }
        }
        else dynamic_direct_Q += LastSignal3;

        if (C_signal[i] == '0' && C_signal[i - 1] == '1')
        {
            if (T_signal[i - 1] == '0')
                dynamic_invert_Q += LastSignal4;
            else if (LastSignal4 == '1')
            {
                dynamic_invert_Q += '0';
                LastSignal4 = '0';
            }
            else
            {
                dynamic_invert_Q += '1';
                LastSignal4 = '1';
            }
        }
        else dynamic_invert_Q += LastSignal4;
    }

    dynamic_direct_Q = GoodSignalToBadSignal(dynamic_direct_Q);
    dynamic_invert_Q = GoodSignalToBadSignal(dynamic_invert_Q);
    cout << "\nQ dlia priamogo dynamichnogo C " << dynamic_direct_Q << "\n";
    cout << "Q dlia inversnogo dynamichnogo C " << dynamic_invert_Q << "\n";
}
