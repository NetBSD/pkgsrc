# $NetBSD: hacks.mk,v 1.2 2013/04/08 11:17:24 rodent Exp $

.include "../../mk/bsd.prefs.mk"

# Workaround for PR 45266
.if ${OPSYS} == "NetBSD"
BUILDLINK_INCDIRS.heimdal=	# empty
.endif
