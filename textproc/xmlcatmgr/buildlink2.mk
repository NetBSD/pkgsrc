# $NetBSD: buildlink2.mk,v 1.3 2003/01/29 20:21:07 jmmv Exp $
#
# This Makefile fragment is included by packages that use xmlcatmgr.
#
# This file was created automatically using createbuildlink 2.3.
#

.if !defined(XMLCATMGR_BUILDLINK2_MK)
XMLCATMGR_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xmlcatmgr
BUILDLINK_DEPENDS.xmlcatmgr?=		xmlcatmgr>=0.2
BUILDLINK_PKGSRCDIR.xmlcatmgr?=		../../textproc/xmlcatmgr

EVAL_PREFIX+=	BUILDLINK_PREFIX.xmlcatmgr=xmlcatmgr
BUILDLINK_PREFIX.xmlcatmgr_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	xmlcatmgr-buildlink

xmlcatmgr-buildlink: _BUILDLINK_USE

.endif	# XMLCATMGR_BUILDLINK2_MK
