/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file SequenceTestServerImplExample.cxx
 * This source file contains the definition of the skeleton for all interfaces.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "SequenceTestServerImplExample.h"

#include <ndds_namespace_cpp.h>
 
largo SequenceTestServerImplExample::getSeqLong(/*in*/ const largo& l1, /*inout*/ largo& l2, /*out*/ largo& l3) 
{
    largo getSeqLong_ret;

	largo_initialize(&l3);
	largo_initialize(&getSeqLong_ret);
        
	largo_copy(&l3, &l2);
	largo_copy(&getSeqLong_ret, &l1);
	l2[0] = l1[0] + l2[0];
	l2[1] = l1[1] + l2[1];
   
    return getSeqLong_ret;
} 
 
cadena SequenceTestServerImplExample::getSeqString(/*in*/ const cadena& s1, /*inout*/ cadena& s2, /*out*/ cadena& s3) 
{
    cadena getSeqString_ret;

	cadena_initialize(&s3);
	cadena_initialize(&getSeqString_ret);
        
	cadena_copy(&s3, &s2);
	cadena_copy(&getSeqString_ret, &s1);
	cadena_copy(&s2, &s1);
   
    return getSeqString_ret;
} 
 
dattos SequenceTestServerImplExample::getSeqDatos(/*in*/ const dattos& sb1, /*inout*/ dattos& sb2, /*out*/ dattos& sb3) 
{
    dattos getSeqDatos_ret;

	dattos_initialize(&sb3);
	dattos_initialize(&getSeqDatos_ret);
        
	dattos_copy(&sb3, &sb2);
	dattos_copy(&getSeqDatos_ret, &sb1);
	dattos_copy(&sb2, &sb1);
   
    return getSeqDatos_ret;
} 

seqdat SequenceTestServerImplExample::getSeqDat(/*in*/ const seqdat& sd1, /*inout*/ seqdat& sd2, /*out*/ seqdat& sd3)
{
    seqdat getSeqDat_ret;

    seqdat_initialize(&sd3);
    seqdat_initialize(&getSeqDat_ret);

    seqdat_copy(&sd3, &sd2);
    seqdat_copy(&getSeqDat_ret, &sd1);
    seqdat_copy(&sd2, &sd1);

    return getSeqDat_ret;
}

SequenceTest::Sequences SequenceTestServerImplExample::getSequences(/*in*/ const SequenceTest::Sequences& seq1, /*inout*/ SequenceTest::Sequences& seq2, /*out*/ SequenceTest::Sequences& seq3)
{
    SequenceTest::Sequences getSequences_ret;

    Sequences_initialize(&seq3);
    Sequences_initialize(&getSequences_ret);

    Sequences_copy(&seq3, &seq2);
    Sequences_copy(&getSequences_ret, &seq1);
    Sequences_copy(&seq2, &seq1);

    return getSequences_ret;
}

void SequenceTestServerImplExample::getArrLong(/*in*/ const larray& lar1, /*inout*/ larray& lar2, /*out*/ larray& lar3)
{
    larray_copy(&lar3, &lar2);
    larray_copy(&lar2, &lar1);
}

void SequenceTestServerImplExample::getArrString(/*in*/ const sarray& sar1, /*inout*/ sarray& sar2, /*out*/ sarray& sar3)
{
    sarray_initialize(&sar3);
    sarray_copy(&sar3, &sar2);
    sarray_copy(&sar2, &sar1);
}

void SequenceTestServerImplExample::getArrSString(/*in*/ const ssarray& ssar1, /*inout*/ ssarray& ssar2, /*out*/ ssarray& ssar3)
{
    ssarray_initialize(&ssar3);
    ssarray_copy(&ssar3, &ssar2);
    ssarray_copy(&ssar2, &ssar1);
}

void SequenceTestServerImplExample::getArrDatos(/*in*/ const darray& dar1, /*inout*/ darray& dar2, /*out*/ darray& dar3)
{
    darray_initialize(&dar3);
    darray_copy(&dar3, &dar2);
    darray_copy(&dar2, &dar1);
}

void SequenceTestServerImplExample::getArrDDatos(/*in*/ const ddarray& ddar1, /*inout*/ ddarray& ddar2, /*out*/ ddarray& ddar3)
{
    ddarray_initialize(&ddar3);
    ddarray_copy(&ddar3, &ddar2);
    ddarray_copy(&ddar2, &ddar1);
}

void SequenceTestServerImplExample::getArrCDatos(/*in*/ const cdarray& cdar1, /*inout*/ cdarray& cdar2, /*out*/ cdarray& cdar3)
{
    cdarray_initialize(&cdar3);
    cdarray_copy(&cdar3, &cdar2);
    cdarray_copy(&cdar2, &cdar1);
}

SequenceTest::Arrays SequenceTestServerImplExample::getArrays(/*in*/ const SequenceTest::Arrays& array1, /*inout*/ SequenceTest::Arrays& array2, /*out*/ SequenceTest::Arrays& array3)
{
    SequenceTest::Arrays getArrays_ret;

    SequenceTest::Arrays_initialize(&getArrays_ret);
    SequenceTest::Arrays_initialize(&array3);

    SequenceTest::Arrays_copy(&array3, &array2);
    SequenceTest::Arrays_copy(&getArrays_ret, &array1);
    SequenceTest::Arrays_copy(&array2, &array1);

    return getArrays_ret;
}
