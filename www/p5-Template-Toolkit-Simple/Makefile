# $NetBSD: Makefile,v 1.1.1.1 2010/04/28 21:28:19 seb Exp $
#

DISTNAME=	Template-Toolkit-Simple-0.03
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Toolkit-Simple/
COMMENT=	Perl 5 module providing a simple Interface to Template Toolkit
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Template/Toolkit/Simple/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML
BUILD_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
