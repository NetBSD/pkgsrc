# $NetBSD: Makefile,v 1.4 2011/08/14 16:05:42 obache Exp $
#

DISTNAME=	Apache2-AuthCASSimple-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache2-AuthCASSimple/
COMMENT=	Apache2 module to authenticate through a CAS server
#LICENSE=	artistic OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Apache2/AuthCASSimple/.packlist
PERL5_MODULE_TYPE=	Module::Install

DEPENDS+=	p5-Apache-Session-Wrapper-[0-9]*:../../www/p5-Apache-Session-Wrapper
DEPENDS+=	p5-Authen-CAS-Client-[0-9]*:../../security/p5-Authen-CAS-Client
DEPENDS+=	p5-Crypt-SSLeay-[0-9]*:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

BUILD_DEPENDS+=	p5-Pod-Coverage-[0-9]*:../../textproc/p5-Pod-Coverage

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
