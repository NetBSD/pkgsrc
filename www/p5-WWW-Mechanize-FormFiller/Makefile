# $NetBSD: Makefile,v 1.5 2018/08/22 09:47:56 wiz Exp $

DISTNAME=	WWW-Mechanize-FormFiller-0.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Mechanize-FormFiller/
COMMENT=	Framework to automate HTML forms
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-Random>=0.05:../../devel/p5-Data-Random
DEPENDS+=	p5-HTML-Form-[0-9]*:../../www/p5-HTML-Form

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/WWW/Mechanize/FormFiller/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
