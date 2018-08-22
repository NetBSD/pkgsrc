# $NetBSD: Makefile,v 1.20 2018/08/22 09:47:32 wiz Exp $

DISTNAME=	Catalyst-Controller-FormBuilder-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Controller-FormBuilder/
COMMENT=	Catalyst FormBuilder Base Controller
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-CGI-FormBuilder>=3.02:../../www/p5-CGI-FormBuilder
DEPENDS+=	p5-Catalyst-Runtime>=5.7:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Data-Inheritable>=0.04:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-Inspector>=1.13:../../devel/p5-Class-Inspector
DEPENDS+=	p5-MRO-Compat>=0.09:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0.37:../../www/p5-Test-WWW-Mechanize-Catalyst
DEPENDS+=	p5-Tie-IxHash>=1.21:../../devel/p5-Tie-IxHash
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=1.19}:../../devel/p5-Scalar-List-Utils

# Recommented
DEPENDS+=	p5-Catalyst-View-TT>=0.23:../../www/p5-Catalyst-View-TT

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Controller/FormBuilder/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
