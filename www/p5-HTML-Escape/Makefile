# $NetBSD: Makefile,v 1.1 2014/11/08 16:16:55 schmonz Exp $

DISTNAME=		HTML-Escape-1.09
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Escape/
COMMENT=		Extremely fast HTML escape
LICENSE=		${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Escape/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
