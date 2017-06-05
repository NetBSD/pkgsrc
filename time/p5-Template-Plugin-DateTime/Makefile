# $NetBSD: Makefile,v 1.13 2017/06/05 14:25:05 ryoon Exp $
#

DISTNAME=	Template-Plugin-DateTime-0.06002
PKGNAME=	p5-${DISTNAME:S/.06/.06./}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-DateTime/
COMMENT=	Template plugin to use DateTime objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime-[0-9]*:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Plugin/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
