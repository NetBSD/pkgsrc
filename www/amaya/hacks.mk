# $NetBSD: hacks.mk,v 1.1.2.2 2012/01/09 04:17:30 sbd Exp $

.include "../../mk/bsd.prefs.mk"

# Workaround for PR 45266
.if ${OPSYS} == "NetBSD"
BUILDLINK_INCDIRS.heimdal=	# empty
.endif

