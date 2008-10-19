# $NetBSD: Makefile,v 1.3 2008/10/19 19:19:17 he Exp $

DISTNAME=	Template-Multilingual-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5tml
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Multilingual/
COMMENT=	Subclass of Template Toolkit supporting multilingual templates

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit>=2.0:../../www/p5-Template-Toolkit

PERL5_PACKLIST=	auto/Template/Multilingual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
