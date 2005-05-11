# $NetBSD: buildlink3.mk,v 1.12 2005/05/11 22:08:19 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
KDELIBS_BUILDLINK3_MK:=	${KDELIBS_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	kdelibs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdelibs}
BUILDLINK_PACKAGES+=	kdelibs

.if !empty(KDELIBS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.kdelibs+=	kdelibs>=3.2.0
BUILDLINK_RECOMMENDED.kdelibs?=	kdelibs>=3.4.0nb1
BUILDLINK_PKGSRCDIR.kdelibs?=	../../x11/kdelibs3

.include "../../x11/kdelibs3/dirs.mk"
.endif	# KDELIBS_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.kdelibs)
PKG_BUILD_OPTIONS.kdelibs!=						\
	cd ${BUILDLINK_PKGSRCDIR.kdelibs} &&				\
	${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.kdelibs=${PKG_BUILD_OPTIONS.kdelibs:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.kdelibs

.if !empty(PKG_BUILD_OPTIONS.kdelibs:Mcups)
.  include "../../print/cups/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
