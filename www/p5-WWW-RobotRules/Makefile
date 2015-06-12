# $NetBSD: Makefile,v 1.10 2015/06/12 10:52:14 wiz Exp $

DISTNAME=	WWW-RobotRules-6.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-RobotRules/
COMMENT=	Perl 5 module database of robots.txt-derived permissions
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/WWW/RobotRules/.packlist

DEPENDS+=	p5-URI>=1.27:../../www/p5-URI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
