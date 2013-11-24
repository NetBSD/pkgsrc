# $NetBSD: Makefile,v 1.18 2013/11/24 10:02:41 wiz Exp $

DISTNAME=	ack-2.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ack/
COMMENT=	Grep-like text finder
LICENSE=	${PERL5_LICENSE}

USE_TOOLS+=		perl
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ack/.packlist
REPLACE_PERL+=		ack

# Avoid ack regenerating itself and frustrating REPLACE_PERL setting
post-configure:
	    ${TOUCH} ${WRKSRC}/ack

DEPENDS+=	p5-File-Next>=0.4:../../devel/p5-File-Next
#DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
BUILD_DEPENDS+=	{perl>=5.8.8,p5-Test-Harness>=2.5}:../../devel/p5-Test-Harness


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
