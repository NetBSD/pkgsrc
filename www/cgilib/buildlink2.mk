# $NetBSD: buildlink2.mk,v 1.1 2003/02/16 23:06:55 seb Exp $
#
# This Makefile fragment is included by packages that use cgilib.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(CGILIB_BUILDLINK2_MK)
CGILIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			cgilib
BUILDLINK_DEPENDS.cgilib?=		cgilib>=0.5nb1
BUILDLINK_PKGSRCDIR.cgilib?=		../../www/cgilib

EVAL_PREFIX+=	BUILDLINK_PREFIX.cgilib=cgilib
BUILDLINK_PREFIX.cgilib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cgilib+=	include/cgi.h
BUILDLINK_FILES.cgilib+=	lib/libcgi.*

BUILDLINK_TARGETS+=	cgilib-buildlink

cgilib-buildlink: _BUILDLINK_USE

.endif	# CGILIB_BUILDLINK2_MK
