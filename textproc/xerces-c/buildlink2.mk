# $NetBSD: buildlink2.mk,v 1.4 2004/02/11 04:06:04 minskim Exp $
#
# This Makefile fragment is included by packages that use xerces-c.
#

.if !defined(XERCES_C_BUILDLINK2_MK)
XERCES_C_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xerces-c
BUILDLINK_DEPENDS.xerces-c?=	xerces-c>=2.3.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c

EVAL_PREFIX+=	BUILDLINK_PREFIX.xerces-c=xerces-c
BUILDLINK_PREFIX.xerces-c_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xerces-c=	include/xercesc/*/*/*/*
BUILDLINK_FILES.xerces-c+=	include/xercesc/*/*/*
BUILDLINK_FILES.xerces-c+=	include/xercesc/*/*
BUILDLINK_FILES.xerces-c+=	lib/libxerces-c*.*

.include "../../converters/libiconv/buildlink2.mk"

BUILDLINK_TARGETS+=	xerces-c-buildlink

xerces-c-buildlink: _BUILDLINK_USE

.endif	# XERCES_C_BUILDLINK2_MK
