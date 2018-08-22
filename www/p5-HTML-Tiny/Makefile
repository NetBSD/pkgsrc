# $NetBSD: Makefile,v 1.15 2018/08/22 09:47:40 wiz Exp $
#

DISTNAME=	HTML-Tiny-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Tiny/
COMMENT=	Lightweight, dependency free HTML/XML generation in Perl
LICENSE=	gnu-gpl-v2 # OR artistic

#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Tiny/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
