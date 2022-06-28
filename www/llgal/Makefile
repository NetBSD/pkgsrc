# $NetBSD: Makefile,v 1.19 2022/06/28 11:37:06 wiz Exp $

DISTNAME=	llgal-0.13.19
PKGREVISION=	5
CATEGORIES=	www graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgoglin/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://bgoglin.free.fr/llgal/
COMMENT=	The llgal is an easy and fast on-line static gallery generator

LICENSE=	gnu-gpl-v2

GITHUB_TAG=	llgal-${PKGVERSION_NOREV}

USE_PKGLOCALEDIR=	yes

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
