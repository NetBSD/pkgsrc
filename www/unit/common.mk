# $NetBSD: common.mk,v 1.2 2021/02/14 13:43:39 otis Exp $

.if !defined(UNITCOMMON_MK)
UNITCOMMON_MK=	defined

DISTNAME?=	unit-${UNIT_VERSION}

.endif

.include "../../www/unit/version.mk"
