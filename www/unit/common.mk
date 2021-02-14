# $NetBSD: common.mk,v 1.1 2021/02/14 11:56:57 otis Exp $

.if !defined(UNITCOMMON_MK)
UNITCOMMON_MK=	defined

DISTNAME?=	unit-${UNIT_VERSION}

.endif

.include "../../wip/unit/version.mk"
