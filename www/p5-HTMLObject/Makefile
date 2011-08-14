# $NetBSD: Makefile,v 1.12 2011/08/14 16:05:56 obache Exp $

DISTNAME=		libhtmlobject-perl-${VERSION}
PKGNAME=		p5-HTMLObject-${VERSION}
PKGREVISION=		3
SVR4_PKGNAME=		p5hto
CATEGORIES=		www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htmlobject/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://htmlobject.sourceforge.net/
COMMENT=		Perl5 module to quickly and easily create Dynamic HTML pages

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Data-FormValidator>=3.59:../../textproc/p5-Data-FormValidator

VERSION=	2.28

PERL5_PACKLIST=		auto/HTMLObject/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
