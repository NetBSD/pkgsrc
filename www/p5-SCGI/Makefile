# $NetBSD: Makefile,v 1.16 2022/06/28 11:37:41 wiz Exp $

DISTNAME=	SCGI-0.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/SCGI
COMMENT=	Perl 5 module to implement SCGI interface
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/SCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
