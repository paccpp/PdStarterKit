/*
// Copyright (c) 2016 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include <m_pd.h>

static t_class *dummy_class;

typedef struct _dummy
{
    t_object    m_obj;
    t_float     m_f;
} t_dummy;

static void *dummy_new(t_symbol *s, int argc, t_atom *argv)
{
    t_dummy *x = (t_dummy *)pd_new(dummy_class);
    if(x)
    {
        signalinlet_new((t_object *)x, 0);
        outlet_new((t_object *)x, &s_signal);
    }
    
    return (x);
}

void dummy_free(t_dummy *x)
{
    ;
}

t_int *dummy_perform(t_int *w)
{
    //t_dummy   *x   = (t_dummy *)(w[1]);
    t_sample  *in1 = (t_sample *)(w[2]);
    t_sample  *in2 = (t_sample *)(w[3]);
    t_sample  *out1 = (t_sample *)(w[4]);
    int n = (int)(w[5]);
    
    for(int i = 0; i < n; ++i)
    {
        *out1++ = *in1++ + *in2++;
    }
    
    return (w+6);
}

void dummy_dsp(t_dummy *x, t_signal **sp)
{
    dsp_add(dummy_perform, 5,
            x,
            sp[0]->s_vec, sp[1]->s_vec,
            sp[2]->s_vec,
            sp[0]->s_n);
}


extern void dummy_tilde_setup(void)
{
    t_class* c = class_new(gensym("dummy~"),
                           (t_newmethod)dummy_new, (t_method)dummy_free,
                           sizeof(t_dummy), CLASS_DEFAULT, 0);
    if(c)
    {
        class_addmethod(c, (t_method)dummy_dsp, gensym("dsp"), A_CANT);
        CLASS_MAINSIGNALIN(c, t_dummy, m_f);
    }
    dummy_class = c;
}
