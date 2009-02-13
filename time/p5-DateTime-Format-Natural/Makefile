# $NetBSD: Makefile,v 1.1.1.1 2009/02/13 23:48:50 abs Exp $

DISTNAME=	DateTime-Format-Natural-0.74
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?DateTime::Format::Natural
COMMENT=	Create machine readable date/time with natural parsing logic

DEPENDS+=	p5-boolean>=0:../../devel/p5-boolean
DEPENDS+=	p5-Date-Calc>=0:../../time/p5-Date-Calc
DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Params-Validate>=0:../../devel/p5-Params-Validate
DEPENDS+=	p5-Term-ReadLine>=1.16:../../devel/p5-Term-ReadLine

PERL5_MODULE_TYPE=  	Module::Build
PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=	#

PERL5_PACKLIST=	auto/DateTime/Format/Natural/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
