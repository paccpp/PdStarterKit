/*
// Copyright (c) 2016 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

// A starter for Pd signal objects written in c++

#include <m_pd.h>

static t_class *pa_starterpp_tilde_class;

typedef struct _pa_starterpp_tilde
{
    t_object    m_obj; // pd object - always placed in first in the object's struct
    
    t_outlet*   m_out;
    t_float     m_f;
    
} t_pa_starterpp_tilde;

static t_int *pa_starterpp_tilde_perform(t_int *w)
{
    //t_pa_starterpp_tilde   *x   = (t_pa_starterpp_tilde *)(w[1]);
    t_sample* in1 = (t_sample *)(w[2]);
    t_sample* in2 = (t_sample *)(w[3]);
    t_sample* out1 = (t_sample *)(w[4]);
    int vecsize = (int)(w[5]);

    while(vecsize--)
    {
        *out1++ = *in1++ + *in2++;
    }

    return (w+6);
}

static void pa_starterpp_tilde_dsp(t_pa_starterpp_tilde* x, t_signal **sp)
{
    dsp_add(pa_starterpp_tilde_perform, 5,
            x,
            sp[0]->s_vec, sp[1]->s_vec,
            sp[2]->s_vec,
            sp[0]->s_n);
}

static void* pa_starterpp_tilde_new(t_symbol* s, int argc, t_atom *argv)
{
    t_pa_starterpp_tilde *x = (t_pa_starterpp_tilde*)pd_new(pa_starterpp_tilde_class);
    if(x)
    {
        signalinlet_new((t_object *)x, 0);
        x->m_out = outlet_new((t_object *)x, &s_signal);
    }
    
    return (x);
}

static void pa_starterpp_tilde_free(t_pa_starterpp_tilde* x)
{
    outlet_free(x->m_out);
}

// Note in c++ you need to wrap the setup method in an extern "C" statement.
extern "C"
{
    extern void setup_pa0x2estarterpp_tilde(void)
    {
        t_class* c = class_new(gensym("pa.starterpp~"),
                               (t_newmethod)pa_starterpp_tilde_new, (t_method)pa_starterpp_tilde_free,
                               sizeof(t_pa_starterpp_tilde), CLASS_DEFAULT, A_GIMME, 0);
        if(c)
        {
            CLASS_MAINSIGNALIN(c, t_pa_starterpp_tilde, m_f);
            class_addmethod(c, (t_method)pa_starterpp_tilde_dsp, gensym("dsp"), A_CANT);
        }
        
        pa_starterpp_tilde_class = c;
    }
}
