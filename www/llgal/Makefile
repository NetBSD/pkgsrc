# $NetBSD: Makefile,v 1.4 2011/08/14 16:05:40 obache Exp $
#

DISTNAME=	llgal-0.13.16
PKGREVISION=	2
CATEGORIES=	www graphics
MASTER_SITES=	http://download.gna.org/llgal/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://home.gna.org/llgal/
COMMENT=	The llgal is an easy and fast on-line static gallery generator

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=yes

USE_LANGUAGES=	# none

USE_TOOLS+=	gmake msgfmt perl:run
PERL5_PACKLIST=	auto/Llgal/.packlist
REPLACE_PERL+=	llgal.in

MAKE_FLAGS+=	PERL_INSTALLDIRS=vendor
MAKE_FLAGS+=	LOCALEDIR=${PREFIX}/${PKGLOCALEDIR}/locale
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFBASE}

INSTALL_TARGET=	install install-man

PKG_SYSCONFSUBDIR=	llgal

DEPENDS+=	p5-Image-ExifTool-[0-9]*:../../graphics/p5-Image-ExifTool
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
