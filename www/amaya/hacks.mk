# $NetBSD: hacks.mk,v 1.1 2012/01/08 22:19:03 dholland Exp $

.include "../../mk/bsd.prefs.mk"

# Workaround for PR 45266
.if ${OPSYS} == "NetBSD"
BUILDLINK_INCDIRS.heimdal=	# empty
.endif

