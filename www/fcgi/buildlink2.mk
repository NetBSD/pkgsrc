# $NetBSD: buildlink2.mk,v 1.1 2003/01/07 11:35:33 uebayasi Exp $
#
# This Makefile fragment is included by packages that use fcgi.
#

.if !defined(FCGI_BUILDLINK2_MK)
FCGI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fcgi
BUILDLINK_DEPENDS.fcgi?=		fcgi>=2.2.2
BUILDLINK_PKGSRCDIR.fcgi?=		../../www/fcgi

EVAL_PREFIX+=	BUILDLINK_PREFIX.fcgi=fcgi
BUILDLINK_PREFIX.fcgi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fcgi+=	include/fastcgi.h
BUILDLINK_FILES.fcgi+=	include/fcgi*.h
BUILDLINK_FILES.fcgi+=	lib/libfcgi++.*
BUILDLINK_FILES.fcgi+=	lib/libfcgi.*


BUILDLINK_TARGETS+=	fcgi-buildlink

fcgi-buildlink: _BUILDLINK_USE

.endif	# FCGI_BUILDLINK2_MK
