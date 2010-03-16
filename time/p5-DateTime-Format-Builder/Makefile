# $NetBSD: Makefile,v 1.5 2010/03/16 17:04:47 sno Exp $

DISTNAME=	DateTime-Format-Builder-0.80
PKGNAME=	p5-${DISTNAME}00
#PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~drolsky/DateTime-Format-Builder/
COMMENT=	Create DateTime parser classes and objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Factory-Util>=1.6:../../devel/p5-Class-Factory-Util
DEPENDS+=	p5-DateTime>=0.12:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Strptime>=1.04:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-Params-Validate>=0.72:../../devel/p5-Params-Validate
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken

PERL5_MODULE_TYPE=   Module::Build

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/DateTime/Format/Builder/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
