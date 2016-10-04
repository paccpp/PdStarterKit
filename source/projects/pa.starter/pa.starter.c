/*
// Copyright (c) 2016 Eliott Paris.
// For information on usage and redistribution, and for a DISCLAIMER OF ALL
// WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

// A starter for pd objects

#include <m_pd.h>

static t_class *pa_starter_class;

typedef struct _pa_starter
{
    t_object    m_obj;
} t_pa_starter;

static void pa_starter_bang(t_pa_starter *x)
{
    post("bang method called");
}

static void *pa_starter_new(t_symbol *name, int argc, t_atom *argv)
{
    t_pa_starter *x = (t_pa_starter *)pd_new(pa_starter_class);
    if(x)
    {
        ;
    }
    
    return (x);
}

static void pa_starter_free(t_pa_starter *x)
{
    ;
}

extern void setup_pa0x2estarter(void)
{
    t_class* c = class_new(gensym("pa.starter"),
                           (t_newmethod)pa_starter_new, (t_method)pa_starter_free,
                           sizeof(t_pa_starter), CLASS_DEFAULT, A_GIMME, 0);
    if(c)
    {
        class_addbang(c, (t_method)pa_starter_bang);
    }
    
    pa_starter_class = c;
}
