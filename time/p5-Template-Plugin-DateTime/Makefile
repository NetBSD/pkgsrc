# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:10 wiz Exp $
#

DISTNAME=	Template-Plugin-DateTime-0.06002
PKGNAME=	p5-${DISTNAME:S/.06/.06./}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Plugin-DateTime
COMMENT=	Template plugin to use DateTime objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime-[0-9]*:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Template/Plugin/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
