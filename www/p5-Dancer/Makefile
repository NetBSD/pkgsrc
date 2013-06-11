# $NetBSD: Makefile,v 1.16 2013/06/11 07:26:08 wen Exp $

DISTNAME=	Dancer-1.3115
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YA/YANICK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perldancer.org/
COMMENT=	Perl 5 lightweight yet powerful web application framework
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Dancer/.packlist

DEPENDS+=	p5-Clone>=0:../../devel/p5-Clone
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Body>=1.07:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Server-Simple-PSGI>=0.11:../../www/p5-HTTP-Server-Simple-PSGI
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-Module-Runtime>=0:../../devel/p5-Module-Runtime
DEPENDS+=	p5-URI>=1.59:../../www/p5-URI
DEPENDS+=	p5-Test-Output>=0:../../devel/p5-Test-Output
DEPENDS+=	p5-Test-TCP>=1.30:../../net/p5-Test-TCP
DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-Try-Tiny>=0.09:../../devel/p5-Try-Tiny
DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
