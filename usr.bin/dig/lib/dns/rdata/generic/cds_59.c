/*
 * Copyright (C) Internet Systems Consortium, Inc. ("ISC")
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
 * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/* draft-ietf-dnsop-delegation-trust-maintainance-14 */

#ifndef RDATA_GENERIC_CDS_59_C
#define RDATA_GENERIC_CDS_59_C

#define RRTYPE_CDS_ATTRIBUTES 0

#include <isc/sha1.h>
#include <isc/sha2.h>

#include <dns/ds.h>

static inline isc_result_t
totext_cds(ARGS_TOTEXT) {

	REQUIRE(rdata->type == dns_rdatatype_cds);

	return (generic_totext_ds(rdata, tctx, target));
}

static inline isc_result_t
fromwire_cds(ARGS_FROMWIRE) {

	REQUIRE(type == dns_rdatatype_cds);

	return (generic_fromwire_ds(rdclass, type, source, dctx, options,
				    target));
}

static inline isc_result_t
towire_cds(ARGS_TOWIRE) {
	isc_region_t sr;

	REQUIRE(rdata->type == dns_rdatatype_cds);
	REQUIRE(rdata->length != 0);

	UNUSED(cctx);

	dns_rdata_toregion(rdata, &sr);
	return (mem_tobuffer(target, sr.base, sr.length));
}







#endif	/* RDATA_GENERIC_CDS_59_C */
