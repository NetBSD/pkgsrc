# $NetBSD: Makefile,v 1.1 2014/05/31 22:20:08 wiz Exp $

DISTNAME=		CGI-Fast-2.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Fast/
COMMENT=		CGI Interface for Fast CGI

DEPENDS+=	p5-CGI>=3.65.02:../../www/p5-CGI
DEPENDS+=	p5-FCGI-[0-9]*:../../www/p5-FCGI

PERL5_PACKLIST=		auto/CGI/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
