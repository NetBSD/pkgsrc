# $NetBSD: Makefile,v 1.12 2011/08/14 16:06:00 obache Exp $

DISTNAME=	Kwiki-Favorites-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Kwiki plugin to bookmark favorite pages

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Kwiki>=0.37nb1:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/Favorites/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
