# $NetBSD: Makefile,v 1.1.1.1 2009/01/06 08:54:21 kefren Exp $

DISTNAME=		sublib-0.9
CATEGORIES=		multimedia textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sublib/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sublib.sourceforge.net/
COMMENT=		Library that eases the development of subtitling applications

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		# empty

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		pre-configure
SUBST_MESSAGE.fix-prefix=	Fixing library installation directory
SUBST_FILES.fix-prefix=		data/sublib.pc.in
SUBST_SED.fix-prefix=		-e 's,@libdir@,@libdir@/mono,'

.include "../../lang/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
