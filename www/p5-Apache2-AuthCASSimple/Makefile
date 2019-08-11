# $NetBSD: Makefile,v 1.16 2019/08/11 13:24:24 wiz Exp $
#

DISTNAME=	Apache2-AuthCASSimple-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Apache2-AuthCASSimple
COMMENT=	Apache2 module to authenticate through a CAS server
#LICENSE=	artistic OR gnu-gpl-v2

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Apache2/AuthCASSimple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-Apache-Session-Wrapper-[0-9]*:../../www/p5-Apache-Session-Wrapper
DEPENDS+=	p5-Authen-CAS-Client-[0-9]*:../../security/p5-Authen-CAS-Client
DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

BUILD_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
