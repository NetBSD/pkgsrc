# $NetBSD: Makefile,v 1.9 2009/10/24 14:42:40 sno Exp $

DISTNAME=	Catalyst-Manual-5.8001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Manual/
COMMENT=	Manual for Catalyst
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Catalyst/Manual/.packlist
#PERL5_MODULE_TYPE=	Module::Install
MAKE_PARAMS+=		--skipdeps
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
