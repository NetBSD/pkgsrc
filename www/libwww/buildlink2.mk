# $NetBSD: buildlink2.mk,v 1.6 2002/12/03 16:47:32 wiz Exp $

.if !defined(LIBWWW_BUILDLINK2_MK)
LIBWWW_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libwww
BUILDLINK_DEPENDS.libwww?=	libwww>=5.3.2nb2
BUILDLINK_PKGSRCDIR.libwww?=	../../www/libwww

EVAL_PREFIX+=			BUILDLINK_PREFIX.libwww=libwww
BUILDLINK_PREFIX.libwww_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libwww=		include/wwwconf.h
BUILDLINK_FILES.libwww+=	include/w3c-libwww/*
BUILDLINK_FILES.libwww+=	lib/libpics.*
BUILDLINK_FILES.libwww+=	lib/libwwwapp.*
BUILDLINK_FILES.libwww+=	lib/libwwwcache.*
BUILDLINK_FILES.libwww+=	lib/libwwwcore.*
BUILDLINK_FILES.libwww+=	lib/libwwwdir.*
BUILDLINK_FILES.libwww+=	lib/libwwwfile.*
BUILDLINK_FILES.libwww+=	lib/libwwwftp.*
BUILDLINK_FILES.libwww+=	lib/libwwwgopher.*
BUILDLINK_FILES.libwww+=	lib/libwwwhttp.*
BUILDLINK_FILES.libwww+=	lib/libwwwhtml.*
BUILDLINK_FILES.libwww+=	lib/libwwwinit.*
BUILDLINK_FILES.libwww+=	lib/libwwwmime.*
BUILDLINK_FILES.libwww+=	lib/libwwwmux.*
BUILDLINK_FILES.libwww+=	lib/libwwwnews.*
BUILDLINK_FILES.libwww+=	lib/libwwwssl.*
BUILDLINK_FILES.libwww+=	lib/libwwwstream.*
BUILDLINK_FILES.libwww+=	lib/libwwwtelnet.*
BUILDLINK_FILES.libwww+=	lib/libwwwtrans.*
BUILDLINK_FILES.libwww+=	lib/libwwwutils.*
BUILDLINK_FILES.libwww+=	lib/libwwwxml.*
BUILDLINK_FILES.libwww+=	lib/libwwwzip.*
BUILDLINK_FILES.libwww+=	lib/libxmlparse.*
BUILDLINK_FILES.libwww+=	lib/libxmltok.*
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "SunOS"
BUILDLINK_FILES.libwww+=	lib/libmd5.*
.endif

.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	libwww-buildlink

libwww-buildlink: _BUILDLINK_USE

.endif	# LIBWWW_BUILDLINK2_MK
