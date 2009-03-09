# $NetBSD: Makefile,v 1.4 2009/03/09 20:34:09 rhaen Exp $

DISTNAME=	Catalyst-Manual-5.7018
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Manual/
COMMENT=	Manual for Catalyst

PERL5_PACKLIST=	auto/Catalyst/Manual/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
