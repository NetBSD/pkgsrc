# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 09:53:02 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libghttp.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGHTTP_BUILDLINK3_MK:=	${LIBGHTTP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libghttp
.endif

.if !empty(LIBGHTTP_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libghttp
BUILDLINK_DEPENDS.libghttp+=		libghttp>=1.0.9
BUILDLINK_PKGSRCDIR.libghttp?=		../../www/libghttp

.endif # LIBGHTTP_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
