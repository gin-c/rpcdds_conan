/*************************************************************************
 * Copyright (c) 2012 eProsima. All rights reserved.
 *
 * This copy of FASTRPC is licensed to you under the terms described in the
 * FASTRPC_LICENSE file included in this distribution.
 *
 *************************************************************************
 * 
 * @file SequenceTestClientExample.cxx
 * This source file shows a simple example of how to create a proxy for an interface.
 *
 * This file was generated by the tool rpcddsgen.
 */

#include "SequenceTestProxy.h"
#include "SequenceTest.h"
#include "SequenceTestDDSProtocol.h"
#include "fastrpc/transports/dds/UDPProxyTransport.h"
#include "fastrpc/exceptions/Exceptions.h"

#include <iostream>

using namespace eprosima::rpc;
using namespace ::exception;
using namespace ::transport::dds;
using namespace ::protocol::dds;

int main(int argc, char **argv)
{
    SequenceTestProtocol *protocol = NULL;
    UDPProxyTransport *transport = NULL;
	SequenceTestProxy *proxy = NULL;
    
    // Creation of the proxy for interface "SequenceTest".
    try
    {
        protocol = new SequenceTestProtocol();
        transport = new UDPProxyTransport("SequenceTestService", "Instance");
        proxy = new SequenceTestProxy(*transport, *protocol);
    }
    catch(InitializeException &ex)
    {
        std::cout << ex.what() << std::endl;
        return -1;
    }

	largo l1;
	largo l2;
	largo l3;
	largo getSeqLong_ret;

	largo_initialize(&l1);
	largo_initialize(&l2);
	largo_initialize(&l3);
	largo_initialize(&getSeqLong_ret);

	l1.ensure_length(2, 2);
	l1.set_at(0, 1);
	l1.set_at(1, 2);
	l2.ensure_length(2, 2);
	l2.set_at(0, 3);
	l2.set_at(1, 4);

	try
	{
		getSeqLong_ret = proxy->getSeqLong(l1, l2, l3);

        if(l3.length() != 2 || l3.get_at(0) != 3 || l3.get_at(1) != 4 ||
                getSeqLong_ret.length() != 2 || getSeqLong_ret.get_at(0) != 1 || getSeqLong_ret.get_at(1) != 2 ||
                l2.length() != 2 || l2.get_at(0) != 4 || l2.get_at(1) != 6 ||
                l1.length() != 2 || l1.get_at(0) != 1 || l1.get_at(1) != 2)
        {
            std::cout << "TEST FAILED<getSeqLong>: Wrong values " << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getSeqLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

	largo_finalize(&l1);    
	largo_finalize(&l2);    
	largo_finalize(&l3);    
	largo_finalize(&getSeqLong_ret);    

	cadena s1;
	cadena s2;
	cadena s3;
	cadena getSeqString_ret;
	char *cadena;
	char *& ref = cadena;

	cadena_initialize(&s1);    
	cadena_initialize(&s2);    
	cadena_initialize(&s3);    
	cadena_initialize(&getSeqString_ret);

	s1.ensure_length(2, 2);
	cadena = DDS_String_dup("PRUEBA");
	s1.set_at(0, (const char*&)ref);
	cadena = DDS_String_dup("PRUEBA2");
	s1.set_at(1, (const char*&)ref);
	s2.ensure_length(2, 2);
	cadena = DDS_String_dup("PRUEBA3");
	s2.set_at(0, (const char*&)ref);
	cadena = DDS_String_dup("PRUEBA4");
	s2.set_at(1, (const char*&)ref);

    try
    {
        getSeqString_ret = proxy->getSeqString(s1, s2, s3);

        if(s3.length() != 2 || strcmp(s3.get_at(0), "PRUEBA3")  != 0 || strcmp(s3.get_at(1), "PRUEBA4")  != 0 ||
                getSeqString_ret.length() != 2 || strcmp(getSeqString_ret.get_at(0), "PRUEBA")  != 0  || strcmp(getSeqString_ret.get_at(1), "PRUEBA2")  != 0 ||
                s2.length() != 2 || strcmp(s2.get_at(0), "PRUEBA")  != 0  || strcmp(s2.get_at(1), "PRUEBA2")  != 0 ||
                s1.length() != 2 || strcmp(s1.get_at(0), "PRUEBA")  != 0  || strcmp(s1.get_at(1), "PRUEBA2")  != 0)
        {
            std::cout << "TEST FAILED<getSeqString>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getSeqString>: " << ex.what() << std::endl;
        _exit(-1);
    }

	cadena_finalize(&s1);    
	cadena_finalize(&s2);    
	cadena_finalize(&s3);    
	cadena_finalize(&getSeqString_ret);    

	dattos sb1;       
	dattos sb2;       
	dattos sb3;    
	dattos getSeqDatos_ret;

	dattos_initialize(&sb1);
	dattos_initialize(&sb2);
	dattos_initialize(&sb3);
	dattos_initialize(&getSeqDatos_ret);

	Datos data;
	sb1.ensure_length(2, 2);
	data.count = 1;
	data.message = DDS_String_dup("PRUEBA");
	sb1.set_at(0, data);
	data.count = 2;
	DDS_String_free(data.message);
	data.message = DDS_String_dup("PRUEBA2");
	sb1.set_at(1, data);
	sb2.ensure_length(2, 2);
	data.count = 3;
	DDS_String_free(data.message);
	data.message = DDS_String_dup("PRUEBA3");
	sb2.set_at(0, data);
	data.count = 4;
	DDS_String_free(data.message);
	data.message = DDS_String_dup("PRUEBA4");
	sb2.set_at(1, data);

    try
    {
        getSeqDatos_ret = proxy->getSeqDatos(sb1, sb2, sb3);

        if(sb3.length() != 2 || sb3.get_at(0).count != 3 || strcmp(sb3.get_at(0).message, "PRUEBA3")  != 0 || sb3.get_at(1).count != 4 || strcmp(sb3.get_at(1).message, "PRUEBA4")  != 0 ||
                getSeqDatos_ret.length() != 2 || getSeqDatos_ret.get_at(0).count != 1 || strcmp(getSeqDatos_ret.get_at(0).message, "PRUEBA")  != 0  || getSeqDatos_ret.get_at(1).count != 2 || strcmp(getSeqDatos_ret.get_at(1).message, "PRUEBA2")  != 0 ||
                sb2.length() != 2 || sb2.get_at(0).count != 1 || strcmp(sb2.get_at(0).message, "PRUEBA")  != 0  || sb2.get_at(1).count != 2 || strcmp(sb2.get_at(1).message, "PRUEBA2")  != 0 ||
                sb1.length() != 2 || sb1.get_at(0).count != 1 || strcmp(sb1.get_at(0).message, "PRUEBA")  != 0  || sb1.get_at(1).count != 2 || strcmp(sb1.get_at(1).message, "PRUEBA2")  != 0)
        {
            std::cout << "TEST FAILED<getSeqDatos>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getSeqDatos>: " << ex.what() << std::endl;
        _exit(-1);
    }


	dattos_finalize(&sb1);    
	dattos_finalize(&sb2);    
	dattos_finalize(&sb3);    
	dattos_finalize(&getSeqDatos_ret);    

    seqdat sd1;
    seqdat sd2;
    seqdat sd3;
    seqdat getSeqDat_ret;

    seqdat_initialize(&sd1);
    seqdat_initialize(&sd2);
    seqdat_initialize(&sd3);
    seqdat_initialize(&getSeqDat_ret);

    sd1.ensure_length(2, 2);
    sd1[0].ensure_length(2, 2);
    sd1[0][0].count = 1;
    sd1[0][0].message = DDS_String_dup("PRUEBA1");
    sd1[0][1].count = 2;
    sd1[0][1].message = DDS_String_dup("PRUEBA2");
    sd1[1].ensure_length(2, 2);
    sd1[1][0].count = 3;
    sd1[1][0].message = DDS_String_dup("PRUEBA3");
    sd1[1][1].count = 4;
    sd1[1][1].message = DDS_String_dup("PRUEBA4");
    sd2.ensure_length(2, 2);
    sd2[0].ensure_length(2, 2);
    sd2[0][0].count = 5;
    sd2[0][0].message = DDS_String_dup("PRUEBA5");
    sd2[0][1].count = 6;
    sd2[0][1].message = DDS_String_dup("PRUEBA6");
    sd2[1].ensure_length(2, 2);
    sd2[1][0].count = 7;
    sd2[1][0].message = DDS_String_dup("PRUEBA7");
    sd2[1][1].count = 8;
    sd2[1][1].message = DDS_String_dup("PRUEBA8");

    try
    {
        getSeqDat_ret = proxy->getSeqDat(sd1, sd2, sd3);

        if(sd3.length() != 2 || sd3[0].length() != 2 || sd3[0][0].count != 5 || strcmp(sd3[0][0].message, "PRUEBA5") != 0 ||
                sd3[0][1].count != 6 || strcmp(sd3[0][1].message, "PRUEBA6") != 0 ||
                sd3[1].length() != 2 || sd3[1][0].count != 7 || strcmp(sd3[1][0].message, "PRUEBA7") != 0 ||
                sd3[1][1].count != 8 || strcmp(sd3[1][1].message, "PRUEBA8") != 0 ||
                getSeqDat_ret.length() != 2 || getSeqDat_ret[0].length() != 2 || getSeqDat_ret[0][0].count != 1 || strcmp(getSeqDat_ret[0][0].message, "PRUEBA1") != 0 ||
                getSeqDat_ret[0][1].count != 2 || strcmp(getSeqDat_ret[0][1].message, "PRUEBA2") != 0 ||
                getSeqDat_ret[1].length() != 2 || getSeqDat_ret[1][0].count != 3 || strcmp(getSeqDat_ret[1][0].message, "PRUEBA3") != 0 ||
                getSeqDat_ret[1][1].count != 4 || strcmp(getSeqDat_ret[1][1].message, "PRUEBA4") != 0 ||
                sd2.length() != 2 || sd2[0].length() != 2 || sd2[0][0].count != 1 || strcmp(sd2[0][0].message, "PRUEBA1") != 0 ||
                sd2[0][1].count != 2 || strcmp(sd2[0][1].message, "PRUEBA2") != 0 ||
                sd2[1].length() != 2 || sd2[1][0].count != 3 || strcmp(sd2[1][0].message, "PRUEBA3") != 0 ||
                sd2[1][1].count != 4 || strcmp(sd2[1][1].message, "PRUEBA4") != 0 ||
                sd1.length() != 2 || sd1[0].length() != 2 || sd1[0][0].count != 1 || strcmp(sd1[0][0].message, "PRUEBA1") != 0 ||
                sd1[0][1].count != 2 || strcmp(sd1[0][1].message, "PRUEBA2") != 0 ||
                sd1[1].length() != 2 || sd1[1][0].count != 3 || strcmp(sd1[1][0].message, "PRUEBA3") != 0 ||
                sd1[1][1].count != 4 || strcmp(sd1[1][1].message, "PRUEBA4") != 0)
        {
            std::cout << "TEST FAILED<getSeqDat>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getSeqDat>: " << ex.what() << std::endl;
        _exit(-1);
    }

    seqdat_finalize(&sd1);
    seqdat_finalize(&sd2);
    seqdat_finalize(&sd3);
    seqdat_finalize(&getSeqDat_ret);

    SequenceTest::Sequences seq1;
    SequenceTest::Sequences seq2;
    SequenceTest::Sequences seq3;
    SequenceTest::Sequences getSequences_ret;

    Sequences_initialize(&seq1);
    Sequences_initialize(&seq2);
    Sequences_initialize(&seq3);
    Sequences_initialize(&getSequences_ret);

    seq1.strings.ensure_length(2, 2);
    seq1.strings[0] = DDS_String_dup("PRUEBA1");
    seq1.strings[1] = DDS_String_dup("PRUEBA2");
    seq1.datos.ensure_length(2, 2);
    seq1.datos[0].count = 1;
    seq1.datos[0].message = DDS_String_dup("PRUEBA1");
    seq1.datos[1].count = 2;
    seq1.datos[1].message = DDS_String_dup("PRUEBA2");
    seq1.seqdat.ensure_length(2, 2);
    seq1.seqdat[0].ensure_length(2, 2);
    seq1.seqdat[0][0].count = 1;
    seq1.seqdat[0][0].message = DDS_String_dup("PRUEBA1");
    seq1.seqdat[0][1].count = 2;
    seq1.seqdat[0][1].message = DDS_String_dup("PRUEBA2");
    seq1.seqdat[1].ensure_length(2, 2);
    seq1.seqdat[1][0].count = 3;
    seq1.seqdat[1][0].message = DDS_String_dup("PRUEBA3");
    seq1.seqdat[1][1].count = 4;
    seq1.seqdat[1][1].message = DDS_String_dup("PRUEBA4");
    seq2.strings.ensure_length(2, 2);
    seq2.strings[0] = DDS_String_dup("PRUEBA5");
    seq2.strings[1] = DDS_String_dup("PRUEBA6");
    seq2.datos.ensure_length(2, 2);
    seq2.datos[0].count = 5;
    seq2.datos[0].message = DDS_String_dup("PRUEBA5");
    seq2.datos[1].count = 6;
    seq2.datos[1].message = DDS_String_dup("PRUEBA6");
    seq2.seqdat.ensure_length(2, 2);
    seq2.seqdat[0].ensure_length(2, 2);
    seq2.seqdat[0][0].count = 5;
    seq2.seqdat[0][0].message = DDS_String_dup("PRUEBA5");
    seq2.seqdat[0][1].count = 6;
    seq2.seqdat[0][1].message = DDS_String_dup("PRUEBA6");
    seq2.seqdat[1].ensure_length(2, 2);
    seq2.seqdat[1][0].count = 7;
    seq2.seqdat[1][0].message = DDS_String_dup("PRUEBA7");
    seq2.seqdat[1][1].count = 8;
    seq2.seqdat[1][1].message = DDS_String_dup("PRUEBA8");

    try
    {
        getSequences_ret = proxy->getSequences(seq1, seq2, seq3);

        if(seq3.strings.length() != 2 || strcmp(seq3.strings[0], "PRUEBA5") != 0 || strcmp(seq3.strings[1], "PRUEBA6") != 0 ||
                seq3.datos.length() != 2 || seq3.datos[0].count != 5 || strcmp(seq3.datos[0].message, "PRUEBA5") != 0 ||
                seq3.datos[1].count != 6 || strcmp(seq3.datos[1].message, "PRUEBA6") != 0 ||
                seq3.seqdat.length() != 2 || seq3.seqdat[0].length() != 2 || seq3.seqdat[0][0].count != 5 || strcmp(seq3.seqdat[0][0].message, "PRUEBA5") != 0 ||
                seq3.seqdat[0][1].count != 6 || strcmp(seq3.seqdat[0][1].message, "PRUEBA6") != 0 ||
                seq3.seqdat[1].length() != 2 || seq3.seqdat[1][0].count != 7 || strcmp(seq3.seqdat[1][0].message, "PRUEBA7") != 0 ||
                seq3.seqdat[1][1].count != 8 || strcmp(seq3.seqdat[1][1].message, "PRUEBA8") != 0 ||
                getSequences_ret.strings.length() != 2 || strcmp(getSequences_ret.strings[0], "PRUEBA1") != 0 || strcmp(getSequences_ret.strings[1], "PRUEBA2") != 0 ||
                getSequences_ret.datos.length() != 2 || getSequences_ret.datos[0].count != 1 || strcmp(getSequences_ret.datos[0].message, "PRUEBA1") != 0 ||
                getSequences_ret.datos[1].count != 2 || strcmp(getSequences_ret.datos[1].message, "PRUEBA2") != 0 ||
                getSequences_ret.seqdat.length() != 2 || getSequences_ret.seqdat[0].length() != 2 || getSequences_ret.seqdat[0][0].count != 1 || strcmp(getSequences_ret.seqdat[0][0].message, "PRUEBA1") != 0 ||
                getSequences_ret.seqdat[0][1].count != 2 || strcmp(getSequences_ret.seqdat[0][1].message, "PRUEBA2") != 0 ||
                getSequences_ret.seqdat[1].length() != 2 || getSequences_ret.seqdat[1][0].count != 3 || strcmp(getSequences_ret.seqdat[1][0].message, "PRUEBA3") != 0 ||
                getSequences_ret.seqdat[1][1].count != 4 || strcmp(getSequences_ret.seqdat[1][1].message, "PRUEBA4") != 0 ||
                seq1.strings.length() != 2 || strcmp(seq1.strings[0], "PRUEBA1") != 0 || strcmp(seq1.strings[1], "PRUEBA2") != 0 ||
                seq1.datos.length() != 2 || seq1.datos[0].count != 1 || strcmp(seq1.datos[0].message, "PRUEBA1") != 0 ||
                seq1.datos[1].count != 2 || strcmp(seq1.datos[1].message, "PRUEBA2") != 0 ||
                seq1.seqdat.length() != 2 || seq1.seqdat[0].length() != 2 || seq1.seqdat[0][0].count != 1 || strcmp(seq1.seqdat[0][0].message, "PRUEBA1") != 0 ||
                seq1.seqdat[0][1].count != 2 || strcmp(seq1.seqdat[0][1].message, "PRUEBA2") != 0 ||
                seq1.seqdat[1].length() != 2 || seq1.seqdat[1][0].count != 3 || strcmp(seq1.seqdat[1][0].message, "PRUEBA3") != 0 ||
                seq1.seqdat[1][1].count != 4 || strcmp(seq1.seqdat[1][1].message, "PRUEBA4") != 0)
        {
            std::cout << "TEST FAILED<getSequences>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getSequences>: " << ex.what() << std::endl;
        _exit(-1);
    }

    Sequences_finalize(&seq1);
    Sequences_finalize(&seq2);
    Sequences_finalize(&seq3);
    Sequences_finalize(&getSequences_ret);

    larray lar1;
    larray lar2;
    larray lar3;

    larray_initialize(&lar1);
    larray_initialize(&lar2);

    lar1[0] = 1;
    lar1[1] = 2;
    lar2[0] = 3;
    lar2[1] = 4;

    try
    {
        proxy->getArrLong(lar1, lar2, lar3);

        if(lar3[0] != 3 || lar3[1] != 4  || lar2[0] != 1 || lar2[1] != 2 || lar1[0] != 1 || lar1[1] != 2)
        {
            std::cout << "TEST FAILED<getArrLong>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrLong>: " << ex.what() << std::endl;
        _exit(-1);
    }

    larray_finalize(&lar1);
    larray_finalize(&lar2);
    larray_finalize(&lar3);

    sarray sar1;
    sarray sar2;
    sarray sar3;

    sarray_initialize(&sar1);
    sarray_initialize(&sar2);

    sar1[0] = DDS_String_dup("PRUEBA1");
    sar1[1] = DDS_String_dup("PRUEBA2");
    sar2[0] = DDS_String_dup("PRUEBA3");
    sar2[1] = DDS_String_dup("PRUEBA4");

    try
    {
        proxy->getArrString(sar1, sar2, sar3);

        if(strcmp(sar3[0], "PRUEBA3") != 0 || strcmp(sar3[1], "PRUEBA4") != 0 || strcmp(sar2[0], "PRUEBA1") != 0 ||
                strcmp(sar2[1], "PRUEBA2") != 0 || strcmp(sar1[0], "PRUEBA1") != 0 || strcmp(sar1[1], "PRUEBA2") != 0)
        {
            std::cout << "TEST FAILED<getArrString>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrString>: " << ex.what() << std::endl;
        _exit(-1);
    }

    sarray_finalize(&sar1);
    sarray_finalize(&sar2);
    sarray_finalize(&sar3);

    ssarray ssar1;
    ssarray ssar2;
    ssarray ssar3;

    ssarray_initialize(&ssar1);
    ssarray_initialize(&ssar2);

    ssar1[0][0] = DDS_String_dup("PRUEBA1");
    ssar1[0][1] = DDS_String_dup("PRUEBA2");
    ssar1[0][2] = DDS_String_dup("PRUEBA3");
    ssar1[1][0] = DDS_String_dup("PRUEBA4");
    ssar1[1][1] = DDS_String_dup("PRUEBA5");
    ssar1[1][2] = DDS_String_dup("PRUEBA6");
    ssar2[0][0] = DDS_String_dup("PRUEBA7");
    ssar2[0][1] = DDS_String_dup("PRUEBA8");
    ssar2[0][2] = DDS_String_dup("PRUEBA9");
    ssar2[1][0] = DDS_String_dup("PRUEBA10");
    ssar2[1][1] = DDS_String_dup("PRUEBA11");
    ssar2[1][2] = DDS_String_dup("PRUEBA12");

    try
    {
        proxy->getArrSString(ssar1, ssar2, ssar3);

        if(strcmp(ssar3[0][0], "PRUEBA7") != 0 || strcmp(ssar3[0][1], "PRUEBA8") != 0 || strcmp(ssar3[0][2], "PRUEBA9") != 0 ||
                strcmp(ssar3[1][0], "PRUEBA10") != 0 || strcmp(ssar3[1][1], "PRUEBA11") != 0 || strcmp(ssar3[1][2], "PRUEBA12") != 0 || 
                strcmp(ssar2[0][0], "PRUEBA1") != 0 || strcmp(ssar2[0][1], "PRUEBA2") != 0 || strcmp(ssar2[0][2], "PRUEBA3") != 0 ||
                strcmp(ssar2[1][0], "PRUEBA4") != 0 || strcmp(ssar2[1][1], "PRUEBA5") != 0 || strcmp(ssar2[1][2], "PRUEBA6") != 0 ||
                strcmp(ssar1[0][0], "PRUEBA1") != 0 || strcmp(ssar1[0][1], "PRUEBA2") != 0 || strcmp(ssar1[0][2], "PRUEBA3") != 0 ||
                strcmp(ssar1[1][0], "PRUEBA4") != 0 || strcmp(ssar1[1][1], "PRUEBA5") != 0 || strcmp(ssar1[1][2], "PRUEBA6") != 0)
        {
            std::cout << "TEST FAILED<getArrSString>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrSString>: " << ex.what() << std::endl;
        _exit(-1);
    }

    ssarray_finalize(&ssar1);
    ssarray_finalize(&ssar2);
    ssarray_finalize(&ssar3);

    darray dar1;
    darray dar2;
    darray dar3;

    darray_initialize(&dar1);
    darray_initialize(&dar2);

    dar1[0].count = 1;
    dar1[0].message = DDS_String_dup("PRUEBA1");
    dar1[1].count = 2;
    dar1[1].message = DDS_String_dup("PRUEBA2");
    dar2[0].count = 3;
    dar2[0].message = DDS_String_dup("PRUEBA3");
    dar2[1].count = 4;
    dar2[1].message = DDS_String_dup("PRUEBA4");

    try
    {
        proxy->getArrDatos(dar1, dar2, dar3);

        if(dar3[0].count != 3 || strcmp(dar3[0].message, "PRUEBA3") != 0 || dar3[1].count != 4 || strcmp(dar3[1].message, "PRUEBA4")  != 0 ||
                dar2[0].count != 1 || strcmp(dar2[0].message, "PRUEBA1") != 0 || dar2[1].count != 2 || strcmp(dar2[1].message, "PRUEBA2") != 0||
                dar1[0].count != 1 || strcmp(dar1[0].message, "PRUEBA1") != 0 || dar1[1].count != 2 || strcmp(dar1[1].message, "PRUEBA2") != 0)
        {
            std::cout << "TEST FAILED<getArrDatos>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrDatos>: " << ex.what() << std::endl;
        _exit(-1);
    }

    darray_finalize(&dar1);
    darray_finalize(&dar2);
    darray_finalize(&dar3);

    ddarray ddar1;
    ddarray ddar2;
    ddarray ddar3;

    ddarray_initialize(&ddar1);
    ddarray_initialize(&ddar2);

    ddar1[0][0].count = 1;
    ddar1[0][0].message = DDS_String_dup("PRUEBA1");
    ddar1[0][1].count = 2;
    ddar1[0][1].message = DDS_String_dup("PRUEBA2");
    ddar1[0][2].count = 3;
    ddar1[0][2].message = DDS_String_dup("PRUEBA3");
    ddar1[1][0].count = 4;
    ddar1[1][0].message = DDS_String_dup("PRUEBA4");
    ddar1[1][1].count = 5;
    ddar1[1][1].message = DDS_String_dup("PRUEBA5");
    ddar1[1][2].count = 6;
    ddar1[1][2].message = DDS_String_dup("PRUEBA6");
    ddar2[0][0].count = 7;
    ddar2[0][0].message = DDS_String_dup("PRUEBA7");
    ddar2[0][1].count = 8;
    ddar2[0][1].message = DDS_String_dup("PRUEBA8");
    ddar2[0][2].count = 9;
    ddar2[0][2].message = DDS_String_dup("PRUEBA9");
    ddar2[1][0].count = 10;
    ddar2[1][0].message = DDS_String_dup("PRUEBA10");
    ddar2[1][1].count = 11;
    ddar2[1][1].message = DDS_String_dup("PRUEBA11");
    ddar2[1][2].count = 12;
    ddar2[1][2].message = DDS_String_dup("PRUEBA12");

    try
    {
        proxy->getArrDDatos(ddar1, ddar2, ddar3);

        if(ddar3[0][0].count != 7 || strcmp(ddar3[0][0].message, "PRUEBA7") != 0 || ddar3[0][1].count != 8 || strcmp(ddar3[0][1].message, "PRUEBA8") != 0 ||
                ddar3[0][2].count != 9 || strcmp(ddar3[0][2].message, "PRUEBA9") != 0|| ddar3[1][0].count != 10 || strcmp(ddar3[1][0].message, "PRUEBA10") != 0 ||
                ddar3[1][1].count != 11 || strcmp(ddar3[1][1].message, "PRUEBA11") != 0|| ddar3[1][2].count != 12 || strcmp(ddar3[1][2].message, "PRUEBA12") != 0 ||
                ddar2[0][0].count != 1 || strcmp(ddar2[0][0].message, "PRUEBA1") != 0 || ddar2[0][1].count != 2 || strcmp(ddar2[0][1].message, "PRUEBA2") != 0||
                ddar2[0][2].count != 3 || strcmp(ddar2[0][2].message, "PRUEBA3") != 0 || ddar2[1][0].count != 4 || strcmp(ddar2[1][0].message, "PRUEBA4") != 0||
                ddar2[1][1].count != 5 || strcmp(ddar2[1][1].message, "PRUEBA5") != 0 || ddar2[1][2].count != 6 || strcmp(ddar2[1][2].message, "PRUEBA6") != 0||
                ddar1[0][0].count != 1 || strcmp(ddar1[0][0].message, "PRUEBA1") != 0 || ddar1[0][1].count != 2 || strcmp(ddar1[0][1].message, "PRUEBA2") != 0||
                ddar1[0][2].count != 3 || strcmp(ddar1[0][2].message, "PRUEBA3") != 0 || ddar1[1][0].count != 4 || strcmp(ddar1[1][0].message, "PRUEBA4") != 0||
                ddar1[1][1].count != 5 || strcmp(ddar1[1][1].message, "PRUEBA5") != 0 || ddar1[1][2].count != 6 || strcmp(ddar1[1][2].message, "PRUEBA6") != 0)
        {
            std::cout << "TEST FAILED<getArrDDatos>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrDDatos>: " << ex.what() << std::endl;
        _exit(-1);
    }

    ddarray_finalize(&ddar1);
    ddarray_finalize(&ddar2);
    ddarray_finalize(&ddar3);

    cdarray cdar1;
    cdarray cdar2;
    cdarray cdar3;

    cdarray_initialize(&cdar1);
    cdarray_initialize(&cdar2);

    cdar1[0].count = 1;
    cdar1[0].message = DDS_String_dup("PRUEBA1");
    cdar1[1].count = 2;
    cdar1[1].message = DDS_String_dup("PRUEBA2");
    cdar2[0].count = 3;
    cdar2[0].message = DDS_String_dup("PRUEBA3");
    cdar2[1].count = 4;
    cdar2[1].message = DDS_String_dup("PRUEBA4");

    try
    {
        proxy->getArrCDatos(cdar1, cdar2, cdar3);

        if(cdar3[0].count != 3 || strcmp(cdar3[0].message, "PRUEBA3") != 0 || cdar3[1].count != 4 || strcmp(cdar3[1].message, "PRUEBA4") != 0 ||
                cdar2[0].count != 1 || strcmp(cdar2[0].message, "PRUEBA1") != 0 || cdar2[1].count != 2 || strcmp(cdar2[1].message, "PRUEBA2") != 0 ||
                cdar1[0].count != 1 || strcmp(cdar1[0].message, "PRUEBA1") != 0 || cdar1[1].count != 2 || strcmp(cdar1[1].message, "PRUEBA2") != 0)
        {
            std::cout << "TEST FAILED<getArrCDatos>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrCDatos>: " << ex.what() << std::endl;
        _exit(-1);
    }

    cdarray_finalize(&cdar1);
    cdarray_finalize(&cdar2);
    cdarray_finalize(&cdar3);

    SequenceTest::Arrays array1;
    SequenceTest::Arrays array2;
    SequenceTest::Arrays array3;

    SequenceTest::Arrays_initialize(&array1);
    SequenceTest::Arrays_initialize(&array2);

    array1.strings[0] = DDS_String_dup("PRUEBA1");
    array1.strings[1] = DDS_String_dup("PRUEBA2");
    array1.stringss[0][0] = DDS_String_dup("PRUEBA1");
    array1.stringss[0][1] = DDS_String_dup("PRUEBA2");
    array1.stringss[0][2] = DDS_String_dup("PRUEBA3");
    array1.stringss[1][0] = DDS_String_dup("PRUEBA4");
    array1.stringss[1][1] = DDS_String_dup("PRUEBA5");
    array1.stringss[1][2] = DDS_String_dup("PRUEBA6");
    array1.datos[0].count = 1;
    array1.datos[0].message = DDS_String_dup("PRUEBA1");
    array1.datos[1].count = 2;
    array1.datos[1].message = DDS_String_dup("PRUEBA2");
    array1.datoss[0][0].count = 1;
    array1.datoss[0][0].message = DDS_String_dup("PRUEBA1");
    array1.datoss[0][1].count = 2;
    array1.datoss[0][1].message = DDS_String_dup("PRUEBA2");
    array1.datoss[0][2].count = 3;
    array1.datoss[0][2].message = DDS_String_dup("PRUEBA3");
    array1.datoss[1][0].count = 4;
    array1.datoss[1][0].message = DDS_String_dup("PRUEBA4");
    array1.datoss[1][1].count = 5;
    array1.datoss[1][1].message = DDS_String_dup("PRUEBA5");
    array1.datoss[1][2].count = 6;
    array1.datoss[1][2].message = DDS_String_dup("PRUEBA6");
    array1.arradat[0][0][0].count = 1;
    array1.arradat[0][0][0].message = DDS_String_dup("PRUEBA1");
    array1.arradat[0][0][1].count = 2;
    array1.arradat[0][0][1].message = DDS_String_dup("PRUEBA2");
    array1.arradat[0][0][2].count = 3;
    array1.arradat[0][0][2].message = DDS_String_dup("PRUEBA3");
    array1.arradat[0][1][0].count = 4;
    array1.arradat[0][1][0].message = DDS_String_dup("PRUEBA4");
    array1.arradat[0][1][1].count = 5;
    array1.arradat[0][1][1].message = DDS_String_dup("PRUEBA5");
    array1.arradat[0][1][2].count = 6;
    array1.arradat[0][1][2].message = DDS_String_dup("PRUEBA6");
    array1.arradat[1][0][0].count = 7;
    array1.arradat[1][0][0].message = DDS_String_dup("PRUEBA7");
    array1.arradat[1][0][1].count = 8;
    array1.arradat[1][0][1].message = DDS_String_dup("PRUEBA8");
    array1.arradat[1][0][2].count = 9;
    array1.arradat[1][0][2].message = DDS_String_dup("PRUEBA9");
    array1.arradat[1][1][0].count = 10;
    array1.arradat[1][1][0].message = DDS_String_dup("PRUEBA10");
    array1.arradat[1][1][1].count = 11;
    array1.arradat[1][1][1].message = DDS_String_dup("PRUEBA11");
    array1.arradat[1][1][2].count = 12;
    array1.arradat[1][1][2].message = DDS_String_dup("PRUEBA12");
    array2.strings[0] = DDS_String_dup("PRUEBA13");
    array2.strings[1] = DDS_String_dup("PRUEBA14");
    array2.stringss[0][0] = DDS_String_dup("PRUEBA13");
    array2.stringss[0][1] = DDS_String_dup("PRUEBA14");
    array2.stringss[0][2] = DDS_String_dup("PRUEBA15");
    array2.stringss[1][0] = DDS_String_dup("PRUEBA16");
    array2.stringss[1][1] = DDS_String_dup("PRUEBA17");
    array2.stringss[1][2] = DDS_String_dup("PRUEBA18");
    array2.datos[0].count = 13;
    array2.datos[0].message = DDS_String_dup("PRUEBA13");
    array2.datos[1].count = 14;
    array2.datos[1].message = DDS_String_dup("PRUEBA14");
    array2.datoss[0][0].count = 13;
    array2.datoss[0][0].message = DDS_String_dup("PRUEBA13");
    array2.datoss[0][1].count = 14;
    array2.datoss[0][1].message = DDS_String_dup("PRUEBA14");
    array2.datoss[0][2].count = 15;
    array2.datoss[0][2].message = DDS_String_dup("PRUEBA15");
    array2.datoss[1][0].count = 16;
    array2.datoss[1][0].message = DDS_String_dup("PRUEBA16");
    array2.datoss[1][1].count = 17;
    array2.datoss[1][1].message = DDS_String_dup("PRUEBA17");
    array2.datoss[1][2].count = 18;
    array2.datoss[1][2].message = DDS_String_dup("PRUEBA18");
    array2.arradat[0][0][0].count = 13;
    array2.arradat[0][0][0].message = DDS_String_dup("PRUEBA13");
    array2.arradat[0][0][1].count = 14;
    array2.arradat[0][0][1].message = DDS_String_dup("PRUEBA14");
    array2.arradat[0][0][2].count = 15;
    array2.arradat[0][0][2].message = DDS_String_dup("PRUEBA15");
    array2.arradat[0][1][0].count = 16;
    array2.arradat[0][1][0].message = DDS_String_dup("PRUEBA16");
    array2.arradat[0][1][1].count = 17;
    array2.arradat[0][1][1].message = DDS_String_dup("PRUEBA17");
    array2.arradat[0][1][2].count = 18;
    array2.arradat[0][1][2].message = DDS_String_dup("PRUEBA18");
    array2.arradat[1][0][0].count = 19;
    array2.arradat[1][0][0].message = DDS_String_dup("PRUEBA19");
    array2.arradat[1][0][1].count = 20;
    array2.arradat[1][0][1].message = DDS_String_dup("PRUEBA20");
    array2.arradat[1][0][2].count = 21;
    array2.arradat[1][0][2].message = DDS_String_dup("PRUEBA21");
    array2.arradat[1][1][0].count = 22;
    array2.arradat[1][1][0].message = DDS_String_dup("PRUEBA22");
    array2.arradat[1][1][1].count = 23;
    array2.arradat[1][1][1].message = DDS_String_dup("PRUEBA23");
    array2.arradat[1][1][2].count = 24;
    array2.arradat[1][1][2].message = DDS_String_dup("PRUEBA24");

    try
    {
        proxy->getArrays(array1, array2, array3);

        if(strcmp(array3.strings[0], "PRUEBA13") != 0 || strcmp(array3.strings[1], "PRUEBA14") != 0 ||
                strcmp(array3.stringss[0][0], "PRUEBA13") != 0 || strcmp(array3.stringss[0][1], "PRUEBA14") != 0 ||
                strcmp(array3.stringss[0][2], "PRUEBA15") != 0 || strcmp(array3.stringss[1][0], "PRUEBA16") != 0 ||
                strcmp(array3.stringss[1][1], "PRUEBA17") != 0 || strcmp(array3.stringss[1][2], "PRUEBA18") != 0 ||
                array3.datos[0].count != 13 || strcmp(array3.datos[0].message, "PRUEBA13") != 0 ||
                array3.datos[1].count != 14 || strcmp(array3.datos[1].message, "PRUEBA14") != 0 ||
                array3.datoss[0][0].count != 13 || strcmp(array3.datoss[0][0].message, "PRUEBA13") != 0 ||
                array3.datoss[0][1].count != 14 || strcmp(array3.datoss[0][1].message, "PRUEBA14") != 0 ||
                array3.datoss[0][2].count != 15 || strcmp(array3.datoss[0][2].message, "PRUEBA15") != 0 ||
                array3.datoss[1][0].count != 16 || strcmp(array3.datoss[1][0].message, "PRUEBA16") != 0 ||
                array3.datoss[1][1].count != 17 || strcmp(array3.datoss[1][1].message, "PRUEBA17") != 0 ||
                array3.datoss[1][2].count != 18 || strcmp(array3.datoss[1][2].message, "PRUEBA18") != 0 ||
                array3.arradat[0][0][0].count != 13 || strcmp(array3.arradat[0][0][0].message, "PRUEBA13") != 0 ||
                array3.arradat[0][0][1].count != 14 || strcmp(array3.arradat[0][0][1].message, "PRUEBA14") != 0 ||
                array3.arradat[0][0][2].count != 15 || strcmp(array3.arradat[0][0][2].message, "PRUEBA15") != 0 ||
                array3.arradat[0][1][0].count != 16 || strcmp(array3.arradat[0][1][0].message, "PRUEBA16") != 0 ||
                array3.arradat[0][1][1].count != 17 || strcmp(array3.arradat[0][1][1].message, "PRUEBA17") != 0 ||
                array3.arradat[0][1][2].count != 18 || strcmp(array3.arradat[0][1][2].message, "PRUEBA18") != 0 ||
                array3.arradat[1][0][0].count != 19 || strcmp(array3.arradat[1][0][0].message, "PRUEBA19") != 0 ||
                array3.arradat[1][0][1].count != 20 || strcmp(array3.arradat[1][0][1].message, "PRUEBA20") != 0 ||
                array3.arradat[1][0][2].count != 21 || strcmp(array3.arradat[1][0][2].message, "PRUEBA21") != 0 ||
                array3.arradat[1][1][0].count != 22 || strcmp(array3.arradat[1][1][0].message, "PRUEBA22") != 0 ||
                array3.arradat[1][1][1].count != 23 || strcmp(array3.arradat[1][1][1].message, "PRUEBA23") != 0 ||
                array3.arradat[1][1][2].count != 24 || strcmp(array3.arradat[1][1][2].message, "PRUEBA24") != 0 ||
                strcmp(array2.strings[0], "PRUEBA1") != 0 || strcmp(array2.strings[1], "PRUEBA2") != 0 ||
                strcmp(array2.stringss[0][0], "PRUEBA1") != 0 || strcmp(array2.stringss[0][1], "PRUEBA2") != 0 ||
                strcmp(array2.stringss[0][2], "PRUEBA3") != 0 || strcmp(array2.stringss[1][0], "PRUEBA4") != 0 ||
                strcmp(array2.stringss[1][1], "PRUEBA5") != 0 || strcmp(array2.stringss[1][2], "PRUEBA6") != 0 ||
                array2.datos[0].count != 1 || strcmp(array2.datos[0].message, "PRUEBA1") != 0 ||
                array2.datos[1].count != 2 || strcmp(array2.datos[1].message, "PRUEBA2") != 0 ||
                array2.datoss[0][0].count != 1 || strcmp(array2.datoss[0][0].message, "PRUEBA1") != 0 ||
                array2.datoss[0][1].count != 2 || strcmp(array2.datoss[0][1].message, "PRUEBA2") != 0 ||
                array2.datoss[0][2].count != 3 || strcmp(array2.datoss[0][2].message, "PRUEBA3") != 0 ||
                array2.datoss[1][0].count != 4 || strcmp(array2.datoss[1][0].message, "PRUEBA4") != 0 ||
                array2.datoss[1][1].count != 5 || strcmp(array2.datoss[1][1].message, "PRUEBA5") != 0 ||
                array2.datoss[1][2].count != 6 || strcmp(array2.datoss[1][2].message, "PRUEBA6") != 0 ||
                array2.arradat[0][0][0].count != 1 || strcmp(array2.arradat[0][0][0].message, "PRUEBA1") != 0 ||
                array2.arradat[0][0][1].count != 2 || strcmp(array2.arradat[0][0][1].message, "PRUEBA2") != 0 ||
                array2.arradat[0][0][2].count != 3 || strcmp(array2.arradat[0][0][2].message, "PRUEBA3") != 0 ||
                array2.arradat[0][1][0].count != 4 || strcmp(array2.arradat[0][1][0].message, "PRUEBA4") != 0 ||
                array2.arradat[0][1][1].count != 5 || strcmp(array2.arradat[0][1][1].message, "PRUEBA5") != 0 ||
                array2.arradat[0][1][2].count != 6 || strcmp(array2.arradat[0][1][2].message, "PRUEBA6") != 0 ||
                array2.arradat[1][0][0].count != 7 || strcmp(array2.arradat[1][0][0].message, "PRUEBA7") != 0 ||
                array2.arradat[1][0][1].count != 8 || strcmp(array2.arradat[1][0][1].message, "PRUEBA8") != 0 ||
                array2.arradat[1][0][2].count != 9 || strcmp(array2.arradat[1][0][2].message, "PRUEBA9") != 0 ||
                array2.arradat[1][1][0].count != 10 || strcmp(array2.arradat[1][1][0].message, "PRUEBA10") != 0 ||
                array2.arradat[1][1][1].count != 11 || strcmp(array2.arradat[1][1][1].message, "PRUEBA11") != 0 ||
                array2.arradat[1][1][2].count != 12 || strcmp(array2.arradat[1][1][2].message, "PRUEBA12") != 0 ||
                strcmp(array1.strings[0], "PRUEBA1") != 0 || strcmp(array1.strings[1], "PRUEBA2") != 0 ||
                strcmp(array1.stringss[0][0], "PRUEBA1") != 0 || strcmp(array1.stringss[0][1], "PRUEBA2") != 0 ||
                strcmp(array1.stringss[0][2], "PRUEBA3") != 0 || strcmp(array1.stringss[1][0], "PRUEBA4") != 0 ||
                strcmp(array1.stringss[1][1], "PRUEBA5") != 0 || strcmp(array1.stringss[1][2], "PRUEBA6") != 0 ||
                array1.datos[0].count != 1 || strcmp(array1.datos[0].message, "PRUEBA1") != 0 ||
                array1.datos[1].count != 2 || strcmp(array1.datos[1].message, "PRUEBA2") != 0 ||
                array1.datoss[0][0].count != 1 || strcmp(array1.datoss[0][0].message, "PRUEBA1") != 0 ||
                array1.datoss[0][1].count != 2 || strcmp(array1.datoss[0][1].message, "PRUEBA2") != 0 ||
                array1.datoss[0][2].count != 3 || strcmp(array1.datoss[0][2].message, "PRUEBA3") != 0 ||
                array1.datoss[1][0].count != 4 || strcmp(array1.datoss[1][0].message, "PRUEBA4") != 0 ||
                array1.datoss[1][1].count != 5 || strcmp(array1.datoss[1][1].message, "PRUEBA5") != 0 ||
                array1.datoss[1][2].count != 6 || strcmp(array1.datoss[1][2].message, "PRUEBA6") != 0 ||
                array1.arradat[0][0][0].count != 1 || strcmp(array1.arradat[0][0][0].message, "PRUEBA1") != 0 ||
                array1.arradat[0][0][1].count != 2 || strcmp(array1.arradat[0][0][1].message, "PRUEBA2") != 0 ||
                array1.arradat[0][0][2].count != 3 || strcmp(array1.arradat[0][0][2].message, "PRUEBA3") != 0 ||
                array1.arradat[0][1][0].count != 4 || strcmp(array1.arradat[0][1][0].message, "PRUEBA4") != 0 ||
                array1.arradat[0][1][1].count != 5 || strcmp(array1.arradat[0][1][1].message, "PRUEBA5") != 0 ||
                array1.arradat[0][1][2].count != 6 || strcmp(array1.arradat[0][1][2].message, "PRUEBA6") != 0 ||
                array1.arradat[1][0][0].count != 7 || strcmp(array1.arradat[1][0][0].message, "PRUEBA7") != 0 ||
                array1.arradat[1][0][1].count != 8 || strcmp(array1.arradat[1][0][1].message, "PRUEBA8") != 0 ||
                array1.arradat[1][0][2].count != 9 || strcmp(array1.arradat[1][0][2].message, "PRUEBA9") != 0 ||
                array1.arradat[1][1][0].count != 10 || strcmp(array1.arradat[1][1][0].message, "PRUEBA10") != 0 ||
                array1.arradat[1][1][1].count != 11 || strcmp(array1.arradat[1][1][1].message, "PRUEBA11") != 0 ||
                array1.arradat[1][1][2].count != 12 || strcmp(array1.arradat[1][1][2].message, "PRUEBA12") != 0)
        {
            std::cout << "TEST FAILED<getArrays>: Wrong values" << std::endl;
            _exit(-1);
        }
    }
    catch(SystemException &ex)
    {
        std::cout << "TEST FAILED<getArrays>: " << ex.what() << std::endl;
        _exit(-1);
    }

    SequenceTest::Arrays_finalize(&array1);
    SequenceTest::Arrays_finalize(&array2);
    SequenceTest::Arrays_finalize(&array3);

    std::cout << "TEST SUCCESFULLY" << std::endl;

	delete(proxy);
    delete(transport);
    delete(protocol);

	_exit(0);
	return 0;
}