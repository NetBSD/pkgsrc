# $NetBSD: Makefile,v 1.22 2023/07/06 09:42:37 wiz Exp $
#

DISTNAME=	HTML-Tiny-1.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Tiny
COMMENT=	Lightweight, dependency free HTML/XML generation in Perl
LICENSE=	gnu-gpl-v2 # OR artistic

#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Tiny/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
