# $NetBSD: Makefile,v 1.10 2017/09/27 06:27:13 wiz Exp $

DISTNAME=		CGI-Fast-2.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Fast/
COMMENT=		CGI Interface for Fast CGI
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-CGI>=4:../../www/p5-CGI
DEPENDS+=	p5-FCGI-[0-9]*:../../www/p5-FCGI
# only for 'make test'
BUILD_DEPENDS+=	p5-CPAN-Changes-[0-9]*:../../devel/p5-CPAN-Changes
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/CGI/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
