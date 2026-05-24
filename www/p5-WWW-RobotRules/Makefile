# $NetBSD: Makefile,v 1.23 2026/05/24 17:54:06 wiz Exp $

DISTNAME=	WWW-RobotRules-6.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OA/OALDERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-RobotRules
COMMENT=	Perl 5 module database of robots.txt-derived permissions
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/WWW/RobotRules/.packlist

DEPENDS+=	p5-URI>=1.27:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
