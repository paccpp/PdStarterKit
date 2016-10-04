/*
// Copyright (c) 2016 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

// A starter for pd signal objects

#include <m_pd.h>

static t_class *pa_starter_tilde_class;

typedef struct _pa_starter_tilde
{
    t_object    m_obj;
    t_float     m_f;
} t_pa_starter_tilde;

static t_int *pa_starter_tilde_perform(t_int *w)
{
    //t_pa_starter_tilde   *x   = (t_pa_starter_tilde *)(w[1]);
    t_sample  *in1 = (t_sample *)(w[2]);
    t_sample  *in2 = (t_sample *)(w[3]);
    t_sample  *out1 = (t_sample *)(w[4]);
    int n = (int)(w[5]);

    int i;
    for(i = 0; i < n; ++i)
    {
        *out1++ = *in1++ + *in2++;
    }

    return (w+6);
}

static void pa_starter_tilde_dsp(t_pa_starter_tilde *x, t_signal **sp)
{
    dsp_add(pa_starter_tilde_perform, 5,
            x,
            sp[0]->s_vec, sp[1]->s_vec,
            sp[2]->s_vec,
            sp[0]->s_n);
}

static void *pa_starter_tilde_new(t_symbol *s, int argc, t_atom *argv)
{
    t_pa_starter_tilde *x = (t_pa_starter_tilde *)pd_new(pa_starter_tilde_class);
    if(x)
    {
        signalinlet_new((t_object *)x, 0);
        outlet_new((t_object *)x, &s_signal);
    }
    
    return (x);
}

static void pa_starter_tilde_free(t_pa_starter_tilde *x)
{
    ;
}

extern void setup_pa0x2estarter_tilde(void)
{
    t_class* c = class_new(gensym("pa.starter~"),
                           (t_newmethod)pa_starter_tilde_new, (t_method)pa_starter_tilde_free,
                           sizeof(t_pa_starter_tilde), CLASS_DEFAULT, 0);
    if(c)
    {
        class_addmethod(c, (t_method)pa_starter_tilde_dsp, gensym("dsp"), A_CANT);
        CLASS_MAINSIGNALIN(c, t_pa_starter_tilde, m_f);
    }
    pa_starter_tilde_class = c;
}
