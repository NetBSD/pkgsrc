# $NetBSD: Makefile,v 1.27 2019/08/11 13:24:38 wiz Exp $

DISTNAME=		HTML-FormFu-2.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-FormFu
COMMENT=		HTML Form Creation, Rendering and Validation Framework
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Captcha-reCAPTCHA>=0.93:../../www/p5-Captcha-reCAPTCHA
DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Clone>=0.31:../../devel/p5-Clone
DEPENDS+=	p5-Config-Any>=0.18:../../devel/p5-Config-Any
DEPENDS+=	p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=	p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES
DEPENDS+=	p5-Data-Visitor>=0.26:../../devel/p5-Data-Visitor
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc
DEPENDS+=	p5-DateTime>=0.54:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.7901:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-Format-Natural-[0-9]*:../../time/p5-DateTime-Format-Natural
DEPENDS+=	p5-DateTime-Format-Strptime>=1.2000:../../time/p5-DateTime-Format-Strptime
DEPENDS+=	p5-DateTime-Locale>=0.45:../../time/p5-DateTime-Locale
DEPENDS+=	p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
DEPENDS+=	p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
DEPENDS+=	p5-HTML-Scrubber-[0-9]*:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-HTML-TokeParser-Simple>=3.14:../../www/p5-HTML-TokeParser-Simple
DEPENDS+=	p5-Hash-Flatten-[0-9]*:../../devel/p5-Hash-Flatten
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
#DEPENDS+=	{perl>=5.10.0,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
#DEPENDS+=	{perl>=5.7.3,p5-Locale-Maketext-[0-9]*}:../../misc/p5-Locale-Maketext
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moose>=1.00:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Attribute-Chained>=1.0.1:../../devel/p5-MooseX-Attribute-Chained
DEPENDS+=	p5-MooseX-Aliases-[0-9]*:../../devel/p5-MooseX-Aliases
DEPENDS+=	p5-MooseX-SetOnce-[0-9]*:../../devel/p5-MooseX-SetOnce
DEPENDS+=	p5-Number-Format-[0-9]*:../../textproc/p5-Number-Format
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Readonly>=0:../../devel/p5-Readonly
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
#DEPENDS+=	p5-Regexp-Copy-[0-9]*:../../textproc/p5-Regexp-Copy
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Template-Toolkit>=2:../../www/p5-Template-Toolkit
DEPENDS+=	p5-YAML-LibYAML>=0.32:../../textproc/p5-YAML-LibYAML
DEPENDS+=	p5-libwww>=5:../../www/p5-libwww

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.92}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		c

PERL5_PACKLIST=		auto/HTML/FormFu/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
