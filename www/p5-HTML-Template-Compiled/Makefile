# $NetBSD: Makefile,v 1.7 2022/06/28 11:37:25 wiz Exp $

DISTNAME=	HTML-Template-Compiled-1.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TI/TINITA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Template-Compiled
COMMENT=	Template System Compiles HTML::Template files to Perl code
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

PERL5_PACKLIST=	auto/HTML/Template/Compiled/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
